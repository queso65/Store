<template>
  <div class="login-center">
    <div style='margin:auto;'> 
    <form action="" method="post" enctype="multipart/form-data">
        <div class="registration__container registration-center">
          <h1 >Регистрация</h1>
          <hr class="registration__line">
          <my-label for="email">Email</my-label>
          <my-input type="text" placeholder="Введите Email" name="email"/>
          
          <my-label for="fname">Имя</my-label>
          <my-input type="text" placeholder="Введите имя" name="fname"/>
          
          <my-label for="lname">Фамилия</my-label>
          <my-input type="text" placeholder="Введите фамилию" name="lname"/>
          
          <my-label for="psw">Пароль</my-label>
          <my-input type="password" placeholder="Введите пароль" name="psw"/>
          
          <my-label for="psw-repeat">Повторите пароль</my-label>
          <my-input type="password" placeholder="Повторите пароль" name="psw-repeat"/>
          <hr class="registration__line">
          <my-button>Зарегистрироваться</my-button>
        </div>
      </form>
      </div>
      </div>
</template>

<script>

</script>

<style scoped>
.registration__container {
	color: #444444;
	font-family: Noto Sans, sans-serif;
	max-width:350px;

}

.login-center{
	display:flex; 
	position:absolute; 
	top:0; 
	bottom:0; 
	right:0; 
	left:0;
}

.registration-center{
	margin:0 auto;
}

.registration__line{
    border: 1px solid #f1f1f1 ;
    margin-bottom: 15px;
}

</style>
