<template>
    <store-header></store-header>
    <store-catalog></store-catalog>

    <div class="shopping-cart exp">
        <div class="header-cart">
            <div class="total__price-cart">Итоговая цена: <span class="total">800 ₽</span></div>
            <button class="total__buton__text-cart total__buton-cart" onclick="">Заказать</button>
        </div>

        <!--  На одной странице не больше 6 товаров! если больше создаем старницы, как в page.html-->

        <div class="item-cart" data-id="">
            <div class="delate__item-cart"><button class="delate__item__text-cart" id="delate__item"
                    data-id="">удалить</button></div>
            <div class="product__inf-cart">
                <img src="../assets/img/T-shirt.jpg" class="image-cart" alt="" />
                <div class="description-cart">футболка</div>
                <div class="item__price-cart">200 ₽</div>
            </div>
        </div>

        <div class="item-cart" data-id="">
            <div class="delate__item-cart"><button class="delate__item__text-cart" id="delate__item"
                    data-id="">удалить</button></div>
            <div class="product__inf-cart">
                <img src="../assets/img/T-shirt.jpg" class="image-cart" alt="" />
                <div class="description-cart">футболка</div>
                <div class="item__price-cart">200 ₽</div>
            </div>
        </div>

        <div class="item-cart" data-id="">
            <div class="delate__item-cart"><button class="delate__item__text-cart" id="delate__item"
                    data-id="">удалить</button></div>
            <div class="product__inf-cart">
                <img src="../assets/img/T-shirt.jpg" class="image-cart" alt="" />
                <div class="description-cart">футболка</div>
                <div class="item__price-cart">200 ₽</div>
            </div>
        </div>

        <div class="item-cart" data-id="">
            <div class="delate__item-cart"><button class="delate__item__text-cart" id="delate__item"
                    data-id="">удалить</button></div>
            <div class="product__inf-cart">
                <img src="../assets/img/T-shirt.jpg" class="image-cart" alt="" />
                <div class="description-cart">футболка</div>
                <div class="item__price-cart">200 ₽</div>
            </div>
        </div>

        <div class="item-cart" data-id="">
            <div class="delate__item-cart"><button class="delate__item__text-cart" id="delate__item"
                    data-id="">удалить</button></div>
            <div class="product__inf-cart">
                <img src="../assets/img/T-shirt.jpg" class="image-cart" alt="" />
                <div class="description-cart">футболка</div>
                <div class="item__price-cart">200 ₽</div>
            </div>
        </div>
    </div>

    <store-footer></store-footer>
</template>

<script>
import StoreHeader from "@/components/StoreHeader.vue";
import StoreCatalog from "@/components/StoreCatalog.vue";
import StoreFooter from "@/components/StoreFooter.vue";

export default{
    components: {
    StoreHeader,
    StoreCatalog,
    StoreFooter,
  },
}
</script>

<style scoped>
.shopping-cart {
    width: 980px;
    min-height: 500px;
    margin: 30px auto;
    border-radius: 6px;
    display: flex;
    flex-direction: column;
}

.header-cart {
    display: flex;
    align-items: center;
    height: 80px;
    border-bottom: 1px solid #E1E8EE;
    padding-left: 10px;
    color: #5E6977;
    font-size: 18px;
}

.total__price-cart {
    height: 30px;
    font-size: 22px;
}

.total__buton-cart {
    width: 200px;
    height: 55px;
    margin-left: 50px;
    background-color: #a53bcc;
    text-align: center;
    border-radius: 10px;
    box-shadow: 2px 2px 4px 1px rgba(0, 0, 0, 0.2);
}

.total__buton__text-cart {
    font-size: 17px;
    color: white;
    font-family: "Comic Sans MS", cursive, sans-serif;
}

.item-cart {
    margin-top: 30px;
    padding-bottom: 20px;
    height: 300px;
    border-bottom: 1px solid #e8cbf2;
    border-left: 1px solid #e8cbf2;
    border-right: 1px solid #e8cbf2;
    border-radius: 10px;
}

.product__inf-cart {
    justify-content: space-around;
    display: flex;
    align-items: center;
    margin-top: 25px;
}

.delate__item-cart {
    margin: 0 auto;
    width: 100%;
    background-color: #e8cbf2;
    height: 50px;
    border-radius: 10px;
    padding-top: 10px;
    text-align: center;
}

.delate__item__text-cart {
    text-align: center;
    color: white;
    width: 980px;
    font-size: 20px;
    font-family: Arial, sans-serif;
}

.delate__item-cart:hover {
    background: #d9d9d9;
}

.image-cart {
    height: 200px;
    width: 160px;
}

.description-cart {
    font-family: Arial, sans-serif;
    color: #444444;
    width: 200px;
}

.item__price-cart {
    display: flex;
    text-align: center;
    font-size: 21px;
    color: #43484D;
}

@media (max-width: 800px) {
    .shopping-cart {
        width: 100%;
        height: auto;
        overflow: hidden;
    }

    .item-cart {
        height: auto;
    }

    .product__inf-cart {
        flex-wrap: wrap;
        justify-content: center;
        margin-top: 0px;
    }

    .description-cart {
        width: 100%;
        text-align: center;
        margin: 10px 0;
    }

    .image-cart {
        text-align: center;
        margin: 0 auto;
    }

    .delate__item-cart {
        border-radius: 10px 10px 0 0;
        width: 160px;
    }

    .item__price-cart {
        padding-top: 10px;
    }
}

@media (max-width: 800px) {
    .header-cart {
        flex-wrap: wrap;
        justify-content: center;
        height: auto;
    }

    .total__buton-cart,
    .total__price-cart {
        text-align: center;
        margin: 10px 0;
    }

    .total__price-cart {
        width: 100%;
    }
}

.exp {
    height: 2050px;
}

.delate__item-cart:hover {
    background: #d5a2e8;
}
</style>