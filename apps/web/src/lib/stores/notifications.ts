import type { BannerNotify, ToastNotify } from "$lib/types";
import { writable } from "svelte/store";





type Notify = 
  ( ToastNotify & {kind: "toast"} ) | 
  ( BannerNotify & {kind: "banner"} );

const createNotifications = () => {

  const { subscribe,update } = writable<Notify[]>([]);
  
  return {
    subscribe,
    add: (nt: Omit<Notify,"id">) => {
      const id = Date.now();

      update(
        (all_n) => {
          const newNt = {...nt,id} as Notify;
          return [...all_n, newNt];
        }
      );

      if(nt.kind == "toast"){

      }

      if(nt.kind == "banner"){
        
      }
    },
    remove: (id:number) => {
      update(
        (all_nt) => all_nt.filter(n => n.id !== id)
      );
    }
  };
};


export const notifications = createNotifications();





