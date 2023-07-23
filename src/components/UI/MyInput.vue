<template>
  <input 
    required class="input__text" 
    :value="modelValue"  
    @input="updateInput"
  />
</template>

<script>
export default {
  name: "my-input",
  props: {
        modelValue: String
    },
    methods: {
        updateInput(event) {
            this.$emit('update:modelValue', event.target.value)
        }
    }
};
</script>

<style>
.input__text {
  font-family: "Comic Sans MS", cursive, sans-serif;
  width: 100%;
  padding: 11px;
  margin: 5px 0 22px 0;
  display: inline-block;
  border: none;
  background: #ebebeb;
  border-radius: 3px;
}

.input__text:focus {
  background-color: #ddd;
  outline: none;
}
</style>


