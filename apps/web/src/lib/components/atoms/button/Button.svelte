<script lang="ts">
  import type { Snippet } from "svelte";

  interface Props {
    onClick: () => void;
    children?: Snippet;
    disabled?: boolean;
    variant?: 'primary' | 'secondary' | 'ghost' | 'danger';
    type?: "button" | "submit" | "reset";
  }

  let { 
    onClick, 
    children, 
    disabled = false, 
    variant = 'primary',
    type = "button"
  }: Props = $props();
</script>

<button 
  {type}
  class="btn {variant}" 
  onclick={onClick} 
  {disabled}
>
  {#if children}
    {@render children()}
  {:else}
    Action
  {/if}
</button>

<style>
  /* --- БАЗОВЫЕ СТИЛИ (Общие для всех кнопок) --- */
  .btn {
    font-family: var(--ff-sans);
    font-size: var(--fs-base);
    font-weight: 600;
    padding: var(--sp-sm) var(--sp-xl);
    border-radius: var(--radius-main);
    cursor: pointer;
    display: inline-flex;
    align-items: center;
    justify-content: center;
    outline: none;
    border: 2px solid transparent; /* Резервируем место под границу */
    transition: all var(--dur-fast) ease;
  }

  .btn:disabled {
    cursor: not-allowed;
    opacity: 0.6;
    transform: none !important;
    box-shadow: none !important;
  }

  /* --- ВАРИАНТЫ (Специфические стили) --- */

  /* Primary */
  .primary {
    background-color: var(--action-primary);
    color: var(--clr-white);
  }
  .primary:hover:not(:disabled) {
    background-color: var(--action-hover);
    transform: translateY(-2px);
    box-shadow: 0 4px 12px rgba(52, 152, 219, 0.3);
  }

  /* Secondary */
  .secondary {
    background-color: transparent;
    color: var(--action-primary);
    border-color: var(--action-primary);
  }
  .secondary:hover:not(:disabled) {
    background-color: var(--clr-blue-100);
  }

  /* Ghost */
  .ghost {
    background-color: transparent;
    color: var(--text-muted);
  }
  .ghost:hover:not(:disabled) {
    background-color: var(--bg-secondary);
    color: var(--text-main);
  }

  /* Danger */
  .danger {
    background-color: var(--clr-error);
    color: var(--clr-white);
  }
  .danger:hover:not(:disabled) {
    filter: brightness(0.9);
    box-shadow: 0 4px 12px rgba(184, 31, 26, 0.3);
  }

  /* Состояние Active для всех */
  .btn:active:not(:disabled) {
    transform: translateY(0);
  }
</style>

