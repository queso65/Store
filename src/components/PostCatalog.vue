<template>
    <div class="menu">
        <div class="container"> 
        <!--  при нажатие нужно показать каталог-->
          <div class="catalog">
            <div 
            class="catalog__wrapper"
            v-bind:class="{ open: isActive }"
            v-on:click="openCatalog"
            >
              <div class="catalog__header ">
                <span>Категории</span><i class="fa fa-bars catalog__header-icon"></i>
              </div>
              <ul class="catalog__list">
                <li class="catalog__item">
                  <a href="" class="catalog__link">футболки</a>						
                </li>
                <li class="catalog__item">
                  <a href="" class="catalog__link">брелки</a>				
                </li>	
                <li class="catalog__item">
                  <a href="" class="catalog__link">канцелярия</a>
                  <div class="catalog__subcatalog">
                    <a href="" class="catalog__subcatalog-link">ручки</a>
                    <a href="" class="catalog__subcatalog-link">блокноты</a>								
                  </div>							
                </li>
                <li class="catalog__item">
                  <a href="" class="catalog__link">сумки</a>				
                </li>
                <li class="catalog__item">
                  <a href="" class="catalog__link">постеры</a>				
                </li>
                <li class="catalog__item">
                  <a href="" class="catalog__link">домашняя одежда</a>				
                </li>
              </ul>
            </div>
          </div>	
          <nav class="menu__nav">
            <a href="/" class="menu__nav-link">Главная</a>
            <a href="/" class="menu__nav-link">Блог</a>
          </nav>	
          <a class="menu__border"></a>				
        </div>
      </div>
</template>

<script>
export default {
    name: "my-catalog",
    data(){
        return{
          isActive: false
        }
    },
    methods: {
      openCatalog(){
        if(this.isActive === false){
          this.isActive = true;
        }
        else {
          this.isActive = false;
        }
      }
    }
}
</script>

<style scoped>
.open ul {
    padding: 0;
    margin: 0;
    display: block;
}

  .container{
      flex-wrap: wrap;
      max-width: 1140px;
      display: flex;
      padding-left: 15px;
      padding-right: 15px;
      margin-top: 0;
      margin-bottom: 0;
      margin-left: auto;
      margin-right: auto;
  }
  
  .menu {
      height: 60px;
  
  }
  
  .catalog {
      width: 260px;
      top: 0;
      font-family: Noto Sans, sans-serif;
      background-color: #fff;
      -moz-user-select: none;
      -khtml-user-select: none;
      -webkit-user-select: none;
      user-select: none;
      z-index:1;
  }
  .catalog__header {
      height: 60px;
      padding-left: 20px;
      padding-right: 20px;
      border: 1px solid #e0e0e0;
      border-radius:10px;
      border-top: none;
      border-bottom: none;
      justify-content: space-between;
      align-items: center;
      display: flex;
  }
  .catalog__header-icon {
      font-size: 21px;
  }
  .catalog__list {
      position: relative;
      z-index: 2;
  }
  
  ul {
      padding: 0;
      margin: 0;
      display: none;
  }
  
  li {
      list-style: none;
      margin: 0;
      padding: 0;
  }
  
  .catalog__link {
      height: 60px;
      font-size: 14px;
      padding-left: 20px;
      padding-right: 20px;
      border: 1px solid #e0e0e0;
      border-bottom: none;
      align-items: center;
      display: flex;
  }
  
  .catalog__subcatalog {
      width: 300px;
      display: flex;
      flex-direction: column;
      flex-wrap: wrap;
      background-color: #fff;
      position: absolute;
      opacity: 0;
      visibility: hidden;
      left: 280px;
      top: 0;
      height: 100%;
      padding: 20px;
      transition: all .3s;
  }
  .catalog__item:hover .catalog__subcatalog { 
      opacity: 1;
      visibility: visible; 
      left: 260px; 
  }
  .catalog__subcatalog-link {
      font-size: 14px;
      color: #111;
      padding-top: 5px;
      padding-bottom: 5px;
  }
  
  .menu__nav {
      padding-left: 50px;
      padding-top: 20px;
      height: 100%;
      display: flex;
  }
  
  .menu__nav-link {
      font-family: Noto Sans, sans-serif;
      width:100px;
      font-size: 15px;
      text-align:center;
      transition: all .3s;
  }
  
  .menu__border{
      display: flex;
      margin-left: auto;
      border-left: 1px solid #e0e0e0;
      padding-left: 40px;
      height: 60px;
  }
  
  @media (max-width: 762px) {
    .catalog__subcatalog,
    .menu__border,
      .menu__nav{
          display: none;
       }
        .catalog{
            width: 100%;
      }
  }
</style>