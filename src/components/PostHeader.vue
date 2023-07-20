<template>
    <head>
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
    </head>
    <header class="header">
        <div class="container align-items_center">
          <a href="index.html" class="logo" title="logo">
            <img src="@/assets/img/logo.png" class="img_logo" alt="Logo">
          </a>
          <div class="header-right">
            <form class="search-form">
              <input type="text" name="id" value="" placeholder="Поиск" class="search search-input">
              <button><i class="fa fa-search search-i"></i></button>
            </form>
            
            <div class="block">
              <div class="subblock">
                <div class="cart-informer" >
                  <button class="cart-informer__button" onclick="window.location.href = 'cart.html';">
                    <span class="cart-informer__count" id="cart_count">5</span>
                    <span class="cart-informer__icon"><i class="fa fa-shopping-cart cart-informer__icon-i"></i></span>
                    <span class="cart-informer__value" id="cart_cost">500 ₽</span>
                  </button>
                </div>
                  
                <div class="login">
                  <button class="button-login" onclick="window.location.href = 'login.html';">
                    Вход
                  </button>
                </div>
                  <!--
                  <div class="dropdown">
                    <button class="dropbtn" onclick="myFunction()"> личный кабинет
                      <i class="fa fa-caret-down"></i>
                    </button>
                    <div class="dropdown-content" id="myDropdown">
                      <a href="">Перейти</a>
                      <a href="">Выход</a>
                    </div>
                  </div> 	
                  -->				
              </div>
            </div>
          </div>
        </div>
      </header>	
</template>

<script>
export default {
    name: "my-header"
}
</script>

<style scoped>
.header{
    background: #a53bcc;
    padding: 35px 0;
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

.align-items_center{
	align-items: center;
}

.header-right{
	flex-wrap: wrap;
    display: flex;
    align-items: center;
    margin-left: auto;
}
.search-form {
	font-family: "Comic Sans MS", cursive, sans-serif;
    display: flex;
    align-items: center;
    margin: 0 auto;
    width: 220px;
    height: 50px;
    border: 3px solid white;
	border-radius: 10px;
    padding-left: 5px;
    padding-right: 10px;
}

.search {
    outline: 0;
    border: none;
    background: none;
}

.search-input {
	font-family: "Comic Sans MS", cursive, sans-serif;
    color: #fff;
    width: 90%;
    height: 100%;
    font-size: 13px;
}

button {
    outline: 0;
    border: none;
    background: none;
    cursor: pointer;
}
.search-i {
    color: #fff;
}

.login,
.cart-informer {
    color: #fff;
    padding-top: 0;
}

.cart-informer{
	padding-left: 20px;
}

.login{
	margin-left: 20px;
}

.cart-informer__button {
    margin-left: auto;
    margin-right: auto;
    display: flex;
    align-items: center;
}

.button-login{
	font-family: "Comic Sans MS", cursive, sans-serif;
    display: flex;
    align-items: center;
	border: 3px solid white;
	border-radius: 10px;
	width: 70px;
    height: 45px;
    justify-content: center; 
	color: #fff;
	font-size: 12px;
	margin:0 auto;
}

.cart-informer__count {
    color: #111;
    font-size: 10px;
    background-color: #fff;
    width: 20px;
    height: 20px;
    margin-right: -2px;
    display: flex;
    align-items: center;
    justify-content: center;    
}

.cart-informer__icon {
    width: 45px;
    height: 45px;
    border: 3px solid white;
	border-radius: 10px;
    display: flex;
    align-items: center;
    justify-content: center;    
}
.cart-informer__icon-i {
    color: #fff;
}
.cart-informer__i, .cart-informer__value {
    color: #fff;
    font-weight: 700;
    font-size: 12px;
	font-family: "Comic Sans MS", cursive, sans-serif;
    padding-left: 10px;
}

@media (max-width: 700px) {
   .logo{
	height:50px;
	width:100%;
	margin:0 auto;
  }
	
  .search-form{
	margin:0 auto;
  }
  
  .block{
	margin-top:15px;
	width:100%;
  }
  
  .header-right{
	margin: 0 auto;
  }
  .subblock{
	margin: 0 auto;
  }
  
  .cart-informer{
	margin-left:-43px;
  }
}

.block{
	display:flex;
}

.subblock{
	align-items: center;
	display:flex;
}

.logo{
	display:flex;
}

.img_logo{
	width:100x;
	height:50px;
	margin:0 auto;
}
</style>