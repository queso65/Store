<template>
  <head>
    <meta charset="utf-8">
    <title>Store</title>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Philosopher:ital@1&display=swap" rel="stylesheet">
    <meta name="viewport" content="width=device-width">
  </head>
  <body>
      <router-view></router-view>
  </body>
</template>

<script>
</script>

<style>
* {
  box-sizing: border-box;
}

html,
body {
  margin: 0;
  font-size: 16px;
}

::-webkit-input-placeholder {
  color: #fff
}

:-moz-placeholder {
  color: #fff
}

::-moz-placeholder {
  color: #fff
}

:-ms-input-placeholder {
  color: #fff
}

button {
  outline: 0;
  border: none;
  background: none;
  cursor: pointer;
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

p {
  margin: 0;
  padding: 0;
}

a {
  color: #111;
  text-decoration: none;
}

a:hover {
  color: #821978;
}

th,
td {
  padding: 10px;
  width: 130px;
  height: 50px;
}

th {
  font-family: 'Philosopher', sans-serif;
  font-size: 15px;
  background: #a53bcc;
  color: white;
}

td {
  background: #eee;
  text-align: center;
}

table td {
  overflow: hidden;
}
</style>
