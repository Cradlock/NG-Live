<script lang="ts">
	import favicon from '$lib/assets/favicon.svg';
    import Header from '$lib/components/organisms/header/Header.svelte';
  import '../styles/global.css';

	let { children } = $props();
</script>

<svelte:head>
	<link rel="icon" href={favicon} />
</svelte:head>



<Header/>

{@render children()}


