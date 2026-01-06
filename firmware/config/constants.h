#pragma once

// ===== SCREEN IDS =====
enum ScreenID {
  SCREEN_STATUS = 0,
  SCREEN_GPS,
  SCREEN_METEO,
  SCREEN_MENU
};

// ===== TIMERS =====
#define SCREEN_IDLE_TIMEOUT_MS 120000   // 2 minutos
#define MENU_TIMEOUT_MS        10000    // 10 segundos
