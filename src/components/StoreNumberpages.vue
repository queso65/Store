<template>
    <div class="pages">
        <div class="page__left"></div>
        <a  v-for="page in totalPages+1" :key="page" :data-id="page" class="page page-text" @click="changePage">{{ page }}</a>
        <div class="page__right"></div>
    </div>
</template>

<script>
export default {
   props: {
    totalPages: Number,
   },
   methods: {
    changePage(event){
        var id = event.target.getAttribute('data-id');
        this.$emit('changePage', id)
    }
   }
}
</script>

<style scoped>
.pages{
	display:flex;
	margin-top: 30px;
	justify-content: center;
}

.page__left{
	font-size:11px;
	width: 25px;
	border-left:none;
	border-radius: 10px 0  0 10px;
}

.page__right{
	font-size:11px;
	width: 25px;
	border-radius: 0 10px  10px 0;
}

.page__right,
.page__left,
.page{
	width: 27px;
	height: 27px;
	background: #e5e5e5;
	border-left:  3px solid #cfcfcf;
	box-shadow: 2px 2px 4px 1px rgba(0, 0, 0, 0.2);
	align-items:center;
	justify-content:center;
	display:flex;
}

.page-text{
	font-family: Arial, sans-serif;
	font-size: 15px;
	color:#8c8c8c;
}
</style>
