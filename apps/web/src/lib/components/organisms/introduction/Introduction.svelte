<script>
    import Button from "$lib/components/atoms/button/Button.svelte";
    import Shimmer from "$lib/components/atoms/shimmer/Shimmer.svelte";
    import Spinner from "$lib/components/atoms/spinner/Spinner.svelte";



</script>




<p>
  Welcome to NG-Live 
  
  <Button
    onClick={()=>{}}
    variant={"secondary"}
  >
    <Spinner size={14} secondaryColor="var(--clr-blue-100)" speed={"500ms"}  />
  </Button>
  

</p>


  <Shimmer 
    width="14px"
    height="14px"
    radius="small"
    secondaryColor="var(--)"
  /> 


<style>

  p{
    color: var(--font-colot-primary);
  }

</style>












