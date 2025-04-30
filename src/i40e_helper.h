 /* SPDX-License-Identifier: GPL-2.0-only */
/* Copyright (C) 2013-2025 Intel Corporation */

#ifndef _I40E_HELPER_H_
#define _I40E_HELPER_H_

#include "i40e_alloc.h"

void i40e_client_device_register(struct i40e_info *ldev, struct i40e_client *client);
void i40e_client_device_unregister(struct i40e_info *ldev);

/* prototype */
inline void i40e_destroy_spinlock_d(struct i40e_spinlock *sp);
inline void i40e_acquire_spinlock_d(struct i40e_spinlock *sp);
inline void i40e_release_spinlock_d(struct i40e_spinlock *sp);

/**
 * i40e_init_spinlock_d - OS specific spinlock init for shared code
 * @sp: pointer to a spinlock declared in driver space
 **/
static inline void i40e_init_spinlock_d(struct i40e_spinlock *sp)
{
	mutex_init((struct mutex *)sp);
}

/**
 * i40e_acquire_spinlock_d - OS specific spinlock acquire for shared code
 * @sp: pointer to a spinlock declared in driver space
 **/
inline void i40e_acquire_spinlock_d(struct i40e_spinlock *sp)
{
	mutex_lock((struct mutex *)sp);
}

/**
 * i40e_release_spinlock_d - OS specific spinlock release for shared code
 * @sp: pointer to a spinlock declared in driver space
 **/
inline void i40e_release_spinlock_d(struct i40e_spinlock *sp)
{
	mutex_unlock((struct mutex *)sp);
}

/**
 * i40e_destroy_spinlock_d - OS specific spinlock destroy for shared code
 * @sp: pointer to a spinlock declared in driver space
 **/
inline void i40e_destroy_spinlock_d(struct i40e_spinlock *sp)
{
	mutex_destroy((struct mutex *)sp);
}
#endif /* _I40E_HELPER_H_ */
