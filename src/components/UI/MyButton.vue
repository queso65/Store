<template>
    <button type="submit" class="registerbtn"><slot></slot></button>
</template>

<script>
export default {
    name: "my-button"
}
</script>

<style scoped>
.registerbtn {
    background-color: #a53bcc;
    color: white;
    padding: 15px 19px;
    margin: 6px 0;
    border: none;
    cursor: pointer;
    width: 100%;
    opacity: 0.9;
	border-radius: 5px;
	font-family: "Comic Sans MS", cursive, sans-serif;
}
</style>
