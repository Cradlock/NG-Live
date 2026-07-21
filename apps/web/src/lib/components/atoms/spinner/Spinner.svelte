<script lang="ts">
  interface Props {
    size?: number; // Размер в пикселях (ширина и высота)
    thickness?: number; // Толщина линии кольца
    color?: string; // Цвет активной части
    secondaryColor?: string; // Цвет фона кольца
    speed?: string; // Скорость вращения (из твоих переменных)
  }

  let { 
    size = 40, 
    thickness = 4, 
    color = 'var(--action-primary)', // Твой основной синий
    secondaryColor = 'var(--clr-gray-100)', // Светло-серый фон
    speed = 'var(--dur-normal)' // Скорость анимации
  }: Props = $props();
</script>

<div 
  class="spinner" 
  style:width="{size}px" 
  style:height="{size}px"
  style:border-width="{thickness}px"
  style:border-color={secondaryColor}
  style:border-top-color={color}
  style:animation-duration={speed}
></div>

<style>
  .spinner {
    display: inline-block;
    border-style: solid;
    border-radius: 50%; /* Делаем круг */
    box-sizing: border-box;
    
    /* Применяем анимацию вращения */
    animation-name: spin;
    animation-iteration-count: infinite;
    animation-timing-function: linear; /* Равномерное вращение */
  }

  /* Определение анимации вращения */
  @keyframes spin {
    from { transform: rotate(0deg); }
    to { transform: rotate(360deg); }
  }
</style>
