<template>
    <div v-if="posts.length > 0">
    <div class="product-gr">
      <post-good 
        v-for="post in posts" 
        :post="post"
        :key="post.id"
        @remove="$emit('remove', post)"
      />
    </div>
    </div>
    <h2 v-else style="color: red">
      Список товаров пуст
   </h2>
  </template>
  
  <script>
  import PostGood from './PostGood.vue';
  export default {
    components: {PostGood},
    props: {
      posts:{
        type: Array,
        required: true,
      }
    }
  }
  </script>
  
  <style scoped>
  .product-gr{
	display: grid;
  grid-gap: 45px;
	grid-template-columns: repeat(auto-fit, minmax(260px, 1fr));
	max-width: 1140px;
	margin: 0 auto;
}
  </style>