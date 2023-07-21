import StoreMain from "@/pages/StoreMain"
import StorePage from "@/pages/StorePage"
import {createRouter, createWebHistory } from "vue-router"

const routes = [
    {
       path:'/',
       component: StorePage
    },
    {
        path:'/page',
        component: StoreMain
     },
]

const router = createRouter({
    routes,
    history: createWebHistory(),
})

export default router;