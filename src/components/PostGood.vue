<template>
    <div class="product-item">
        <img src="{{post.img}}">
        <div class="product-list">
            <h3 class="item_title">{{post.title}}</h3>
            <span class="price"><span class="item_price"> {{post.price}}</span> ₽</span>
            <button data-id="" class="button add_item">В корзину</button>
        </div>
    </div>
</template>
  
  <script>
  export default {
    props: {
        post: {
          type: Object,
          required: true 
        }
    }
  }
  
  </script>
  
  <style scoped>
.product-item {
   margin: auto;
   width: 250px;
   text-align: center;
   background: white;
   font-family: Arial, sans-serif;
   transition: .3s ease-in;
}

.product-item img {
   height:317px;
   border-radius: 20px 20px 0 0; 
   display: block;
   width: 100%;
}
.product-list {
   border-radius: 0 0 20px 20px;
   background: #f2f2f2;
   padding: 15px 0;
}
.product-list h3 {
   font-size: 18px;
   font-weight: 400;
   color: #444444;
   margin: 0 0 10px 0;
}
.price {
   font-size: 16px;
   color: #fc5a5a;
   display: block;
   margin-bottom: 12px;
}
.button {
   text-decoration: none;
   display: inline-block;
   padding: 0 12px;
   background: #cccccc;
   color: white;
   text-transform: uppercase;
   font-size: 12px;
   line-height: 28px;
   transition: .3s ease-in;
}
.product-item:hover .button {
   background: #a53bcc;
}







</style>