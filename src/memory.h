// Commander X16 Emulator
// Copyright (c) 2019 Michael Steil
// All rights reserved. License: 2-clause BSD

#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <SDL.h>

#define USE_CURRENT_BANK (-1)
#define debug_read6502(a, b) real_read65816(0, a, true, b)
#define debug_read65816(k, a, b) real_read65816(k, a, true, b)

uint8_t read65816(uint8_t procbank, uint16_t address);
uint8_t real_read65816(uint8_t procbank, uint16_t address, bool debugOn, int16_t bank);
void write65816(uint8_t procbank, uint16_t address, uint8_t value);
void vp6502();

void memory_init();
void memory_reset();
void memory_report_uninitialized_access(bool);
void memory_report_usage_statistics(const char *filename);
void memory_randomize_ram(bool);

void memory_save(SDL_RWops *f, bool dump_ram, bool dump_bank);
void memory_dump_usage_counts();

void memory_set_ram_bank(uint8_t bank);
void memory_set_rom_bank(uint8_t bank);

uint8_t memory_get_ram_bank();
uint8_t memory_get_rom_bank();

uint8_t emu_read(uint8_t reg, bool debugOn);
void emu_write(uint8_t reg, uint8_t value);

#endif
