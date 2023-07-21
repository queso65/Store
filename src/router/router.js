import StoreMain from "@/pages/StoreMain"
import StorePage from "@/pages/StorePage"
import StoreLogin from "@/pages/StoreLogin"
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
     {
        path:'/login',
        component: StoreLogin
     },
]

const router = createRouter({
    routes,
    history: createWebHistory(),
})

export default router;