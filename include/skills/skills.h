#ifndef SKILLS_H
#define SKILLS_H

#include <general.h>
#include <crafting.h>
#include <fighter.h>
#include <thief.h>
#include <cleric.h>
#include <mage.h>
#include <paladin.h>
#include <ranger.h>
#include <psi.h>
#include <bard.h>
#include <medic.h>
#include <pointman.h>
#include <scout.h>
#include <techman.h>

#define STARTUP_CLASSES ({ "fighter", })
#define HP_PER_LEVEL ({ "mage", 7, "thief", 12, "psi", 10,\
 "paladin", 12,\
 "ranger", 12,\
 "bard",   12,\
 "cleric", 9, "fighter", 15, "pointman", 15, "medic", 9, "scout", 12, "techman", 8, })
 

#endif /* SKILLS_H */
