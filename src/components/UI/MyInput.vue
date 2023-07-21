<template>
    <input required class="input__text">
</template>

<script>
export default {
    name: 'my-input'
}
</script>

<style>
.input__text{
	font-family: "Comic Sans MS", cursive, sans-serif;
    width: 100%;
    padding: 11px;
    margin: 5px 0 22px 0;
    display: inline-block;
    border: none;
    background: #ebebeb;
	border-radius:3px;
}

.input__text:focus {
    background-color: #ddd;
    outline: none;
}
</style>


