<template>
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
          <button type="submit" class="registerbtn" name="submit">Зарегистрироваться</button>
        </div>
      </form>
</template>

<script>

</script>

<style scoped>

</style>
