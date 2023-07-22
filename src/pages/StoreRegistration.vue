<template>
  <div class="login-center">
    <div style="margin: auto">
      <form action="" method="post" enctype="multipart/form-data">
        <div class="registration__container registration-center">
          <h1>Регистрация</h1>
          <hr class="registration__line" />

          <my-label for="email">Email</my-label>
          <my-input
            v-model="user.amail"
            type="text"
            placeholder="Введите Email"
            name="email"
          />

          <my-label for="name">Имя</my-label>
          <my-input
            v-model="user.name"
            type="text"
            placeholder="Введите имя"
            name="name"
          />

          <my-label for="psw">Пароль</my-label>
          <my-input
            v-model="user.password"
            type="password"
            placeholder="Введите пароль"
            name="psw"
          />

          <my-label for="psw-repeat">Повторите пароль</my-label>
          <my-input
            v-model="passcheck"
            type="password"
            placeholder="Повторите пароль"
            name="psw-repeat"
          />

          <hr class="registration__line" />
          <my-button @click="regUser">Зарегистрироваться</my-button>
        </div>
      </form>
    </div>
  </div>
</template>

<script>
export default {
  data() {
    return {
      user: {
        name: "",
        password: "",
        amail: "",
      },
      passcheck: "",
      message: 1,
    };
  },
  methods: {
    async regUser() {},
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

.registration-center {
  margin: 0 auto;
}

.registration__line {
  border: 1px solid #f1f1f1;
  margin-bottom: 15px;
}
</style>
