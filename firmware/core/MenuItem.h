#pragma once

typedef void (*MenuAction)();

struct MenuItem {
  const char* label;
  MenuAction action;
};
