<template>
  <div v-if="posts.length > 0">
    <div class="product-gr">
      <store-good
        v-for="post in posts"
        :post="post"
        :key="post.id"
        @remove="$emit('remove', post)"
      />
      <store-good
        v-for="post in 9 - posts.length"
        :key="post"
        :post="emptyPost"
        v-bind:class="{ not__visibility: true }"
      />
    </div>
  </div>
</template>
  
<script>
import StoreGood from "./StoreGood.vue";
export default {
  components: { StoreGood },
  data() {
    return {
      emptyPost: { id: -1, img: "", title: "", price: "" },
    };
  },
  props: {
    posts: {
      type: Array,
      required: true,
    },
  },
};
</script>
  
<style scoped>
.not__visibility {
  visibility: hidden;
}
.product-gr {
  display: grid;
  grid-gap: 45px;
  grid-template-columns: repeat(auto-fit, minmax(260px, 1fr));
  max-width: 1140px;
  margin: 0 auto;
}
</style>