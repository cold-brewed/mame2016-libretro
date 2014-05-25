// license:BSD-3-Clause
// copyright-holders:Curt Coder
/**********************************************************************

    Sandy SuperQBoard (with HD upgrade) emulation

    Copyright MESS Team.
    Visit http://mamedev.org for licensing and usage restrictions.

**********************************************************************/

#pragma once

#ifndef __SANDY_SUPERQBOARD__
#define __SANDY_SUPERQBOARD__

#include "exp.h"
#include "bus/centronics/ctronics.h"
#include "machine/wd_fdc.h"



//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

// ======================> sandy_superqboard_device

class sandy_superqboard_t : public device_t,
			   				public device_ql_expansion_card_interface
{
public:
	// construction/destruction
	sandy_superqboard_t(const machine_config &mconfig, const char *tag, device_t *owner, UINT32 clock);

	// optional information overrides
	virtual const rom_entry *device_rom_region() const;
	virtual machine_config_constructor device_mconfig_additions() const;

	WRITE_LINE_MEMBER( busy_w );

protected:
	// device-level overrides
	virtual void device_start();
	virtual void device_reset();

	// device_ql_expansion_card_interface overrides
    virtual UINT8 read(address_space &space, offs_t offset, UINT8 data);
    virtual void write(address_space &space, offs_t offset, UINT8 data);

private:
	required_device<wd1772_t> m_fdc;
	required_device<floppy_connector> m_floppy0;
	required_device<floppy_connector> m_floppy1;
	required_device<centronics_device> m_centronics;
	required_device<output_latch_device> m_latch;
	required_memory_region m_rom;
	optional_shared_ptr<UINT8> m_ram;

	int m_busy;
	int m_int2;
	int m_int3;
};


// device type definition
extern const device_type SANDY_SUPERQBOARD;


#endif