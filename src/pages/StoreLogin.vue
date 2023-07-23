<template>
  <div class="login-center">
    <div style="margin: auto">
      <form @submit.prevent>
        <div class="registration__container">
          <h1>Авторизация</h1>
          <hr class="registration__line" />

          <my-label for="email">Email</my-label>
          <my-input v-model="user.email" type="text" placeholder="Введите Email" name="email" />

          <my-label for="psw">Пароль</my-label>
          <my-input v-model="user.password" type="password" placeholder="Введите пароль" name="psw" />

          <hr class="registration__line" />
          <my-button @click="logUser">Войти</my-button>

          <div class="registration__container signin">
            <p>
              Нет аккаунта?
              <a @click="$router.push('/registration')" class="dodgerblue">Зарегистрироваться</a>
            </p>
          </div>
        </div>
      </form>
    </div>
  </div>
</template>

<script>
import axios from 'axios';

export default {
  data() {
    return {
      user: {
        email: "",
        password: "",
      },
      passcheck: "",
      message: 1,
    };
  },
  methods: {
    async logUser() {
            
            console.log({ author: this.user })
            const res = await axios.post('http://127.0.0.1:8000/api/users/log/', { user: this.user });
            const out = res.data;
            console.log({ out })
            if (out) {
                this.logstat = 1;
                this.$emit('log', this.user.email);
                this.$router.push('/')
                this.user = {
                    name: '',
                    password: ''
                }
            }
        }
    },
};
</script>

<style scoped>
.registration__container {
  color: #444444;
  font-family: Noto Sans, sans-serif;
  max-width: 350px;
}

.login-center {
  display: flex;
  position: absolute;
  top: 0;
  bottom: 0;
  right: 0;
  left: 0;
}

.registration__line {
  border: 1px solid #f1f1f1;
  margin-bottom: 15px;
}

.registerbtn:hover {
  opacity: 1;
}

.signin {
  margin-top: 10px;
  background-color: #f1f1f1;
  text-align: center;
  padding: 20px;
}

.dodgerblue {
  color: dodgerblue;
}
</style>
