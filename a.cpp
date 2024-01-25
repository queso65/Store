#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <mutex>
#include <ctime>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>

#ifdef WIN32
#include <windows.h>
#include <tchar.h>
#else
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <errno.h>
#include <sys/file.h>
#include <csignal>
#endif


#ifdef WIN32
HANDLE testMutex = NULL;
#endif

#ifdef WIN32 
HANDLE logMutex = CreateMutex(NULL, FALSE, "logMutex_");
HANDLE counterMutex = CreateMutex(NULL, FALSE, "counterMutex_");
HANDLE copyOneExistsMutex = CreateMutex(NULL, FALSE, "copyOneExistsMutex_");
HANDLE copyTwoExistsMutex = CreateMutex(NULL, FALSE, "copyTwoExistsMutex_");
#else
sem_t* logMutex = sem_open("logMutex_", O_CREAT, 0666, 1);
sem_t* counterMutex = sem_open("counterMutex_", O_CREAT, 0666, 1);
sem_t* copyOneExistsMutex = sem_open("copyOneExistsMutex_", O_CREAT, 0666, 1);
sem_t* copyTwoExistsMutex = sem_open("copyTwoExistsMutex_", O_CREAT, 0666, 1);
sem_t* mainPidMutex = sem_open("mainPidMutex_", O_CREAT, 0666, 1);
#endif

std::ofstream logFile("log.txt", std::ios::app);

struct SharedData {
    int counter;
    bool copyOneExists;
    bool copyTwoExists;
#ifdef __linux__
    pid_t mainPid;
#endif
};


auto currentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);
#ifdef WIN32
    std::tm* time_info = std::localtime(&current_time);
#else
    auto time_info = std::put_time(std::localtime(&current_time), "%F %T");
#endif

    return time_info;
}

auto currentMilliseconds() {
    auto now = std::chrono::system_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    return ms;
}

void displayStart() {
#ifdef WIN32
    WaitForSingleObject(logMutex, INFINITE);
    logFile << "########_Start_########  " << GetCurrentProcessId();
    logFile << "    " << std::put_time(currentTime(), "%Y-%m-%d %H.%M.%S") << '.' << currentMilliseconds().count();
    logFile << "  ########_Start_########" << std::endl;
    ReleaseMutex(logMutex);
#else
    sem_wait(logMutex);
    logFile << "########_Start_########  " << getpid();
    logFile << "    " << currentTime() << '.' << currentMilliseconds().count();
    logFile << "  ########_Start_########" << std::endl;
    sem_post(logMutex);
#endif
}

void displayClose() {
#ifdef WIN32
    WaitForSingleObject(logMutex, INFINITE);
    logFile << "********_Close_********  " << GetCurrentProcessId();
    logFile << "    " << std::put_time(currentTime(), "%Y-%m-%d %H.%M.%S") << '.' << currentMilliseconds().count();
    logFile << "  ********_Close_********" << std::endl;
    ReleaseMutex(logMutex);
#else
    sem_wait(logMutex);
    logFile << "********_Close_********  " << getpid();
    logFile << "    " << currentTime() << '.' << currentMilliseconds().count();
    logFile << "  ********_Close_********" << std::endl;
    sem_post(logMutex);
#endif
}

void displayCopyAlreadyExists(int number) {
#ifdef WIN32
    WaitForSingleObject(logMutex, INFINITE);
    logFile << "Cannot create a copy, copy " << number << " already exists" << std::endl;
    ReleaseMutex(logMutex);
#else
    sem_wait(logMutex);
    logFile << "Cannot create a copy, copy " << number << " already exists" << std::endl;
    sem_post(logMutex);
#endif
}


void consoleThread(SharedData* sharedData) {
    while (true) {
        int newValue = 0;
        std::cout << "Enter a new int for the counter: ";
        if ((std::cin >> newValue).good()) {
#ifdef WIN32
            WaitForSingleObject(counterMutex, INFINITE);
            sharedData->counter = newValue;
            ReleaseMutex(counterMutex);
#else
            sem_wait(counterMutex);
            sharedData->counter = newValue;
            sem_post(counterMutex);
#endif
        }
        else {
            newValue = 0;
            std::cin.clear();
            std::cout << "Invalid input format" << std::endl;
            std::cin.ignore(10, '\n');
        }
    }
}


void timerThread(SharedData* sharedData) {
    while (true) {
#ifdef WIN32
        Sleep(3000);
        WaitForSingleObject(counterMutex, INFINITE);
        sharedData->counter++;
        ReleaseMutex(counterMutex);
#else
        sleep(3);
        sem_wait(counterMutex);
        sharedData->counter++;
        sem_post(counterMutex);
#endif     
    }
}


void loggingThread(SharedData* sharedData) {
    while (true) {
#ifdef WIN32
        WaitForSingleObject(counterMutex, INFINITE);
        int counter = sharedData->counter;
        ReleaseMutex(counterMutex);
#else
        sem_wait(counterMutex);
        int counter = sharedData->counter;
        sem_post(counterMutex);

#endif

#ifdef WIN32
        WaitForSingleObject(logMutex, INFINITE);
        logFile << std::put_time(currentTime(), "%Y-%m-%d %H.%M.%S") << '.' << currentMilliseconds().count() << "    " << GetCurrentProcessId() << "    " << counter << std::endl;
        ReleaseMutex(logMutex);
        Sleep(1000);
#else
        sem_wait(logMutex);
        logFile << currentTime() << '.' << currentMilliseconds().count() << "    " << getpid() << "    " << counter << std::endl;

        sem_post(logMutex);
        sleep(1);
#endif
    }
}

#ifdef WIN32
void createChildProcess(int number) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    char command[100];
    char path[MAX_PATH];
    SearchPath(NULL, "logger.exe", NULL, MAX_PATH, path, NULL);
    sprintf(command, "\"%s\" %d", path, number);

    CreateProcess(NULL, command, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
}
#endif

void copyFunction1(SharedData* sharedData) {
#ifdef WIN32
    WaitForSingleObject(counterMutex, INFINITE);
    sharedData->counter = sharedData->counter + 10;
    ReleaseMutex(counterMutex);
#else
    sem_wait(counterMutex);
    sharedData->counter = sharedData->counter + 10;
    sem_post(counterMutex);
#endif
}

void copyFunction2(SharedData* sharedData) {
#ifdef WIN32
    WaitForSingleObject(counterMutex, INFINITE);
    sharedData->counter = sharedData->counter * 2;
    ReleaseMutex(counterMutex);
#else
    sem_wait(counterMutex);
    sharedData->counter = sharedData->counter * 2;
    sem_post(counterMutex);
#endif

#ifdef WIN32
    Sleep(2000);
#else
    sleep(2);
#endif

#ifdef WIN32
    WaitForSingleObject(counterMutex, INFINITE);
    sharedData->counter = sharedData->counter / 2;
    ReleaseMutex(counterMutex);
#else
    sem_wait(counterMutex);
    sharedData->counter = sharedData->counter / 2;
    sem_post(counterMutex);
#endif
}

void cernelCopy(std::string id, SharedData* sharedData) {
#ifdef WIN32
    HANDLE hMapFile;
    LPCTSTR pBuf;
    hMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, "MyFileMappingObject");
    pBuf = (LPTSTR)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(SharedData));
    sharedData = (SharedData*)pBuf;
#endif

    if (id == "1") {
        copyFunction1(sharedData);
#ifdef WIN32
        WaitForSingleObject(copyOneExistsMutex, INFINITE);
        sharedData->copyOneExists = false;
        ReleaseMutex(copyOneExistsMutex);
#else
        sem_wait(copyOneExistsMutex);
        sharedData->copyOneExists = false;
        sem_post(copyOneExistsMutex);
#endif
    }

    if (id == "2") {
        copyFunction2(sharedData);
#ifdef WIN32
        WaitForSingleObject(copyTwoExistsMutex, INFINITE);
        sharedData->copyTwoExists = false;
        ReleaseMutex(copyTwoExistsMutex);
#else
        sem_wait(copyTwoExistsMutex);
        sharedData->copyTwoExists = false;
        sem_post(copyTwoExistsMutex);
#endif
    }

    displayClose();


#ifdef WIN32
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);
#else
    exit(0);
#endif
}

void createCopy(SharedData* sharedData, bool* copyExistsPointer, int number) {
    bool copyExists = false;

    if (number == 1) {
#ifdef WIN32
        WaitForSingleObject(copyOneExistsMutex, INFINITE);
        copyExists = sharedData->copyOneExists;
        ReleaseMutex(copyOneExistsMutex);
#else
        sem_wait(copyOneExistsMutex);
        copyExists = sharedData->copyOneExists;
        sem_post(copyOneExistsMutex);
#endif
    }

    if (number == 2) {
#ifdef WIN32
        WaitForSingleObject(copyTwoExistsMutex, INFINITE);
        copyExists = sharedData->copyTwoExists;
        ReleaseMutex(copyTwoExistsMutex);
#else
        sem_wait(copyTwoExistsMutex);
        copyExists = sharedData->copyTwoExists;
        sem_post(copyTwoExistsMutex);
#endif
    }

    if (copyExists == false) {
        *copyExistsPointer = true;
#ifdef WIN32
        createChildProcess(number);
#else
        pid_t pid = fork();
        if (pid == 0) {
            displayStart();

            cernelCopy(std::to_string(number), sharedData);
        }
#endif
    }
    else {
        displayCopyAlreadyExists(number);
    }
}


void createCopies(SharedData* sharedData) {
    while (true) {
#ifdef WIN32
        Sleep(3000);
#else
        sleep(3);
#endif
        createCopy(sharedData, &(sharedData->copyOneExists), 1);
        createCopy(sharedData, &(sharedData->copyTwoExists), 2);
    }
}

SharedData* createSharedMemory() {
#ifdef WIN32
    HANDLE hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof(SharedData), "MyFileMappingObject");
    LPCTSTR pBuf = (LPTSTR)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(SharedData));
    SharedData* sharedData = (SharedData*)pBuf;


    WaitForSingleObject(copyOneExistsMutex, INFINITE);
    sharedData->copyOneExists = false;
    ReleaseMutex(copyOneExistsMutex);

    WaitForSingleObject(copyTwoExistsMutex, INFINITE);
    sharedData->copyTwoExists = false;
    ReleaseMutex(copyTwoExistsMutex);

    WaitForSingleObject(counterMutex, INFINITE);
    sharedData->counter = 0;
    ReleaseMutex(counterMutex);

#else
    auto shm = shm_open("MySharedMemory", O_CREAT | O_RDWR, 0777);
    ftruncate(shm, sizeof(SharedData));
    SharedData* sharedData = (SharedData*)mmap(0, sizeof(SharedData), PROT_WRITE | PROT_READ, MAP_SHARED, shm, 0);

    sem_wait(counterMutex);
    sharedData->counter = 0;
    sem_post(counterMutex);

    sem_wait(copyOneExistsMutex);
    sharedData->copyOneExists = false;
    sem_post(copyOneExistsMutex);

    sem_wait(copyTwoExistsMutex);
    sharedData->copyTwoExists = false;
    sem_post(copyTwoExistsMutex);
#endif

    return sharedData;
}


void minorProgram() {
#ifdef WIN32
    HANDLE hMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, "MyFileMappingObject");
    LPCTSTR pBuf = (LPTSTR)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(SharedData));
    SharedData* sharedData = (SharedData*)pBuf;
#else
    auto shm = shm_open("MySharedMemory", O_RDWR, 0777);
    ftruncate(shm, sizeof(SharedData));
    SharedData* sharedData = (SharedData*)mmap(0, sizeof(SharedData), PROT_WRITE | PROT_READ, MAP_SHARED, shm, 0);
#endif

    std::thread console(consoleThread, sharedData);
    std::thread timer(timerThread, sharedData);

    timer.join();
    console.join();
}

#ifdef __linux__
bool isAlreadyRunning() {
    std::ifstream lockFile("my_program.lock");
    if (lockFile.good()) {
        lockFile.close();
        return true;
    }
    else {
        std::ofstream newLockFile("my_program.lock");
        return false;
    }
}
#endif


#ifdef __linux__
void signalHeandler(int signum) {
    auto shm = shm_open("MySharedMemory", O_RDWR, 0777);
    ftruncate(shm, sizeof(SharedData));
    SharedData* sharedData = (SharedData*)mmap(0, sizeof(SharedData), PROT_WRITE | PROT_READ, MAP_SHARED, shm, 0);

    sem_wait(mainPidMutex);
    pid_t pid = sharedData->mainPid;
    sem_post(mainPidMutex);

    if (signum == SIGINT || signum == SIGHUP) {
        if (pid == getpid()) {
            std::remove("my_program.lock");
        }
    }
    std::exit(signum);
}
#endif

int main(int argc, char* argv[]) {

#ifdef __linux__
    std::signal(SIGINT, signalHeandler);
    std::signal(SIGHUP, signalHeandler);
#endif

    displayStart();

#ifdef WIN32
    if (argc == 2) {
        HANDLE hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof(SharedData), "MyFileMappingObject");
        LPCTSTR pBuf = (LPTSTR)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(SharedData));
        SharedData* sharedData = (SharedData*)pBuf;
        cernelCopy(std::string(argv[1]), sharedData);
        return 0;
    }
#endif


#ifdef WIN32
    testMutex = CreateMutex(NULL, FALSE, "testMutex_");
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        minorProgram();
        return 0;
    }
#else
    if (isAlreadyRunning()) {
        minorProgram();
        return 0;
    }
#endif
    else {
        SharedData* sharedData = createSharedMemory();
        
#ifdef __linux__
        sem_wait(mainPidMutex);
        sharedData->mainPid = getpid();
        sem_post(mainPidMutex);
#endif
        
        std::thread copies(createCopies, sharedData);
        std::thread console(consoleThread, sharedData);
        std::thread logging(loggingThread, sharedData);
        std::thread timer(timerThread, sharedData);

        console.join();
        logging.join();
        timer.join();
        copies.join();

    }

    return 0;
}
