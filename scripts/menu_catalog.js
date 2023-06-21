 let menuElem = document.getElementById('catalog');
 let titleElem = menuElem.querySelector('.catalog__header');
 titleElem.onclick = function() {
    menuElem.classList.toggle('open');
};