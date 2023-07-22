<template>
  <label><b class="registration__point"><slot></slot></b></label>
</template>

<script>
export default {
  name: "my-label",
};
</script>

<style>
.registration__point {
  font-size: 15px;
  color: #444444;
}
</style>
