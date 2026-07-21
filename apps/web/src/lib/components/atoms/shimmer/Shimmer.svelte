<script lang="ts">
  interface Props {
    width?: string | number;
    height?: string | number;
    radius?: 'none' | 'small' | 'main' | 'full';
    className?: string;
  }

  let { 
    width = '100%', 
    height = '100%', 
    radius = 'main', // По умолчанию используем твое скругление
    className = "" 
  }: Props = $props();

  // Маппинг скруглений на твои CSS переменные
  const radiusMap = {
    none: '0',
    small: '4px',
    main: 'var(--radius-main)',
    full: '9999px'
  };
</script>

<div 
  class="shimmer-wrapper {className}"
  style:width={typeof width === 'number' ? width + 'px' : width}
  style:height={typeof height === 'number' ? height + 'px' : height}
  style:border-radius={radiusMap[radius]}
>
  <div class="shimmer-effect"></div>
</div>

<style>
  .shimmer-wrapper {
    overflow: hidden; /* Чтобы градиент не вылезал */
    background-color: var(--bg-secondary); /* Базовый фон скелетона */
    position: relative;
    border: 1px solid var(--border-subtle);
  }

  .shimmer-effect {
    position: absolute;
    top: 0; left: 0; width: 100%; height: 100%;
    
    /* Создаем блик градиентом */
    background: linear-gradient(
      90deg, 
      transparent 0%, 
      var(--clr-white) 50%, 
      transparent 100%
    );
    opacity: 0.3; /* Делаем блик мягким */
    
    /* Применяем анимацию движения блика */
    animation: shimmer 1.5s infinite linear;
    background-size: 200% 100%; /* Чтобы градиент мог двигаться */
  }

  /* Анимация движения градиента слева направо */
  @keyframes shimmer {
    0% { background-position: 200% 0; }
    100% { background-position: -200% 0; }
  }
</style>
