<template>
      <store-header></store-header>
      <store-catalog></store-catalog>

      <h1 class="сategory">Все товары</h1>
  
      <!--  На одной странице по 9 товаров-->
      <store-list :posts="posts" @remove="removePost" />
  
      <div class="pages">
        <div class="page__left"></div>
        <a data-id="" class="page page-text" href="page.html">1</a>
        <a data-id="" class="page page-text" href="page.html">2</a>
        <a data-id="" class="page page-text" href="page.html">3</a>
        <a data-id="" class="page page-text" href="last_page.html">4</a>
        <div class="page__right"></div>
      </div>
  
      <store-footer></store-footer>
  </template>
  
  <script>
  import StoreList from '@/components/StoreList.vue'
  import StoreHeader from '@/components/StoreHeader.vue'
  import StoreCatalog from '@/components/StoreCatalog.vue'
  import StoreFooter from '@/components/StoreFooter.vue'
  export default {
    components: {
      StoreList,
      StoreHeader,
      StoreCatalog,
      StoreFooter
    },
    data() {
      return {
        posts: [
          { id: 1, img: "http://1001goroskop.ru/img/gadanie/derevo_zh/_derevo.jpg", title: "футболка", price: "200" },
          { id: 2, img: "src/assets/img/T-shirt.jpg", title: "футболка", price: "200" },
          { id: 3, img: "/../assets/img/logo.png", title: "футболка", price: "200" },
          { id: 4, img: "../assets/img/T-shirt.jpg", title: "футболка", price: "200" },
          { id: 5, img: "folder/assets/img/T-shirt.jpg", title: "футболка", price: "200" },
          { id: 6, img: "@/assets/img/T-shirt.jpg", title: "футболка", price: "200" },
          { id: 7, img: "@/assets/img/T-shirt.jpg", title: "футболка", price: "200" },
          { id: 8, img: "@/assets/img/T-shirt.jpg", title: "футболка", price: "200" },
          { id: 9, img: "@/assets/img/T-shirt.jpg", title: "футболка", price: "200" },
        ],
      }
    },
    methods: {
      removePost(post) {
        this.posts = this.posts.filter(p => p.id !== post.id)
      },
    }
  }
  
  </script>
  
  <style>
  .сategory {
    font-family: 'Philosopher', sans-serif;
    text-align: center;
    color: #a53bcc;
    font-size: 28px;
  }
  </style>