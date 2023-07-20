<template>
  <head>
    <meta charset="utf-8">
    <title>Store</title>
    <link rel="stylesheet" type="text/css" href="@/css/font-awesome.min.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Philosopher:ital@1&display=swap" rel="stylesheet">
    <link rel="stylesheet" type="text/css" href="css/style.css">
    <meta name="viewport" content="width=device-width">
  </head>
  
  <body>	
    <store-header></store-header>
    <store-catalog></store-catalog>
    
    
    <h1 class="сategory">Все товары</h1>
    
    <!--  На одной странице по 9 товаров-->
    <store-list 
        :posts="posts"
        @remove="removePost"
    />

    <div class="pages">
      <div class="page__left"></div>
      <a data-id="" class="page page-text" href="page.html">1</a>
      <a data-id="" class="page page-text" href="page.html">2</a>
      <a data-id="" class="page page-text" href="page.html">3</a>
      <a data-id="" class="page page-text" href="last_page.html">4</a>
      <div class="page__right"></div>
    </div>

    <div class="grey__background">
      <div id="footer">
        <p>Ponyshop&trade;2023</p>
      </div>
    </div>
</body>
</template>

<script>
    import StoreList from './components/StoreList.vue'
    import StoreHeader from './components/StoreHeader.vue'
    import StoreCatalog from './components/StoreCatalog.vue'
    export default {
      components: {
        StoreList,
        StoreHeader,
        StoreCatalog
      },
      data(){
        return{
          posts: [
            {id: 1, img: "http://1001goroskop.ru/img/gadanie/derevo_zh/_derevo.jpg", title: "футболка", price: "200"},
            {id: 2, img: "@/assets/img/T-shirt.jpg", title: "футболка", price: "200"},
            {id: 3, img: "@/assets/img/T-shirt.jpg", title: "футболка", price: "200"},
            {id: 4, img: "@/assets/img/T-shirt.jpg", title: "футболка", price: "200"},
            {id: 5, img: "@/assets/img/T-shirt.jpg", title: "футболка", price: "200"},
            {id: 6, img: "@/assets/img/T-shirt.jpg", title: "футболка", price: "200"},
            {id: 7, img: "@/assets/img/T-shirt.jpg", title: "футболка", price: "200"},
            {id: 8, img: "@/assets/img/T-shirt.jpg", title: "футболка", price: "200"},
            {id: 9, img: "@/assets/img/T-shirt.jpg", title: "футболка", price: "200"},
          ],
        }
      },
      methods: {
        removePost(post){
          this.posts = this.posts.filter(p => p.id !== post.id)
        },
      }
    }

</script>

<style>
*{
  box-sizing: border-box;
}

html, body{
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

th,td{
  padding: 10px;
  width:130px;
  height:50px;
 }
 
 th{
  font-family: 'Philosopher', sans-serif;
  font-size:15px;
  background: #a53bcc;
  color: white;
 }
 td{
  background: #eee;
  text-align:center;
 }

table td {
overflow:hidden;
}

.сategory{
	font-family: 'Philosopher', sans-serif;
	text-align:center;
	color: #a53bcc;
	font-size:28px;
}

</style>
