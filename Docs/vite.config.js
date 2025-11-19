import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'

export default defineConfig({
  plugins: [react()],
  base: '/Popnwrap/', // Add this line - make sure it matches your repo name exactly
})