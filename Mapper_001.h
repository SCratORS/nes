#pragma once

#include "Mapper.h"

class Mapper_001 : public Mapper
{
public:
	Mapper_001(uint8_t prgBanks, uint8_t chrBanks);
	~Mapper_001();

	bool CPUMapAddress(uint16_t addr, uint32_t &mapped_addr, uint8_t &data, bool write = false) override;
	bool PPUMapAddress(uint16_t addr, uint32_t &mapped_addr, bool write = false) override;
	void reset() override;
	uint8_t mirror() override {return reg.mirrormode;}
	bool irqState() override { return 0;}
	void irqClear() override {}
	void LoadState(uint8_t * state) override;
	uint8_t * SaveState() override;
	uint32_t GetMapperSize() override { return sizeof(mapper);}
	void scanline(int16_t cycle, int16_t scanline, uint8_t mask, uint8_t control) override {}


private:
	struct mapper {
		uint8_t nCHRBankSelect4Lo = 0x00;
		uint8_t nCHRBankSelect4Hi = 0x00;
		uint8_t nCHRBankSelect8 = 0x00;
		uint8_t nPRGBankSelect16Lo = 0x00;
		uint8_t nPRGBankSelect16Hi = 0x00;
		uint8_t nPRGBankSelect32 = 0x00;
		uint8_t nLoadRegister = 0x00;
		uint8_t nLoadRegisterCount = 0x00;
		uint8_t nControlRegister = 0x00;
		uint8_t mirrormode = 0x01;
		uint8_t vRAMStatic[0x8000];	
	} reg;
};

