#ifndef __SPELLEFFECT_H
#define __SPELLEFFECT_H
/*-------------------------------------------------------------------------*\
  <spelleffect.h> -- Spell Effect header file

  Date      Programmer  Description
  11/07/00  Dennis      Created.
\*-------------------------------------------------------------------------*/

#include "istdlib.h"
#include <file.h>
#include "xmlserializer.h"
#include "dice.h"
#include "btconst.h"

class BTDisplay;
class BTCombat;
class BTCombatantCollection;
class BTCombatant;
class BTGame;

class BTAllResistException
{
 public:
  BTAllResistException() {}
};

class BTBaseEffect : public XMLObject
{
 public:
  BTBaseEffect(int t, int x, int s, int m);

  virtual int apply(BTDisplay &d, BTCombat *combat, int g = BTTARGET_NONE, int trgt = BTTARGET_INDIVIDUAL);
  virtual int maintain(BTDisplay &d, BTCombat *combat);
  virtual void finish(BTDisplay &d, BTCombat *combat, int g = BTTARGET_NONE, int trgt = BTTARGET_INDIVIDUAL);
  virtual void serialize(ObjectSerializer *s);

  virtual bool targets(int g, int who, bool exact = true);
  virtual bool targetsMonsters();
  virtual void move(int g, int who, int where);
  virtual void remove(BTCombat *combat, int g, int who);

  bool isExpired(BTGame *g);

  int type;
  int expiration;
  bool expire;
  bool first;
  int singer;
  int musicId;
};

class BTTargetedEffect : public BTBaseEffect
{
 public:
  BTTargetedEffect(int t, int x, int s, int m, int g, int trgt);

  virtual bool targets(int g, int who, bool exact = true);
  virtual bool targetsMonsters();
  virtual void move(int g, int who, int where);
  virtual void remove(BTCombat *combat, int g, int who);

  int group;
  int target;
};

class BTResistedEffect : public BTTargetedEffect
{
 public:
  BTResistedEffect(int t, int x, int s, int m, int g, int trgt);

  bool checkResists(BTCombat *combat, int g = BTTARGET_NONE, int trgt = BTTARGET_INDIVIDUAL);

  BitField resists;
};

class BTAttackEffect : public BTResistedEffect
{
 public:
  BTAttackEffect(int t, int x, int s, int m, int rng, int erng, int d, int g, int trgt, const BTDice &dam, int sts);

  virtual int apply(BTDisplay &d, BTCombat *combat, int g = BTTARGET_NONE, int trgt = BTTARGET_INDIVIDUAL);
  virtual int maintain(BTDisplay &d, BTCombat *combat);
  virtual void finish(BTDisplay &d, BTCombat *combat, int g = BTTARGET_NONE, int trgt = BTTARGET_INDIVIDUAL);
  virtual void move(int g, int who, int where);
  virtual void remove(BTCombat *combat, int g, int who);

  void displayResists(BTDisplay &d, BTCombat *combat);
  int applyToGroup(BTDisplay &d, BTCombatantCollection *grp, int resistOffset = 0);

  int range;
  int effectiveRange;
  int distance;
  BTDice damage;
  int status;
};

class BTCureStatusEffect : public BTTargetedEffect
{
 public:
  BTCureStatusEffect(int t, int x, int s, int m, int g, int trgt, int sts);

  virtual int maintain(BTDisplay &d, BTCombat *combat);

  int status;
};

class BTHealEffect : public BTTargetedEffect
{
 public:
  BTHealEffect(int t, int x, int s, int m, int g, int trgt, const BTDice& h);

  virtual int maintain(BTDisplay &d, BTCombat *combat);

  BTDice heal;
};

class BTSummonMonsterEffect : public BTTargetedEffect
{
 public:
  BTSummonMonsterEffect(int t, int x, int s, int m, int g, int trgt);

  virtual void finish(BTDisplay &d, BTCombat *combat, int g = BTTARGET_NONE, int trgt = BTTARGET_INDIVIDUAL);
};

class BTSummonIllusionEffect : public BTTargetedEffect
{
 public:
  BTSummonIllusionEffect(int t, int x, int s, int m, int g, int trgt);

  virtual void finish(BTDisplay &d, BTCombat *combat, int g = BTTARGET_NONE, int trgt = BTTARGET_INDIVIDUAL);
};

class BTDispellIllusionEffect : public BTTargetedEffect
{
 public:
  BTDispellIllusionEffect(int t, int x, int s, int m, int rng, int erng, int d, int g, int trgt);

  virtual int maintain(BTDisplay &d, BTCombat *combat);

  int applyToGroup(BTDisplay &d, BTCombatantCollection *grp);
  int apply(BTDisplay &d, BTCombatant *target);

  int range;
  int effectiveRange;
  int distance;
};

class BTArmorBonusEffect : public BTTargetedEffect
{
 public:
  BTArmorBonusEffect(int t, int x, int s, int m, int g, int trgt, int b);

  virtual int apply(BTDisplay &d, BTCombat *combat, int g = BTTARGET_NONE, int trgt = BTTARGET_INDIVIDUAL);
  virtual void finish(BTDisplay &d, BTCombat *combat, int g = BTTARGET_NONE, int trgt = BTTARGET_INDIVIDUAL);

  int bonus;
};

class BTHitBonusEffect : public BTTargetedEffect
{
 public:
  BTHitBonusEffect(int t, int x, int s, int m, int g, int trgt, int b);

  virtual int apply(BTDisplay &d, BTCombat *combat, int g = BTTARGET_NONE, int trgt = BTTARGET_INDIVIDUAL);
  virtual void finish(BTDisplay &d, BTCombat *combat, int g = BTTARGET_NONE, int trgt = BTTARGET_INDIVIDUAL);

  int bonus;
};

class BTResurrectEffect : public BTTargetedEffect
{
 public:
  BTResurrectEffect(int t, int x, int s, int m, int g, int trgt);

  virtual int maintain(BTDisplay &d, BTCombat *combat);
};

class BTDispellMagicEffect : public BTTargetedEffect
{
 public:
  BTDispellMagicEffect(int t, int x, int s, int m, int rng, int erng, int d, int g, int trgt);

  virtual int maintain(BTDisplay &d, BTCombat *combat);

  int range;
  int effectiveRange;
  int distance;
};

class BTPhaseDoorEffect : public BTBaseEffect
{
 public:
  BTPhaseDoorEffect(int t, int x, int s, int m, int mX, int mY, int f);

  int mapX;
  int mapY;
  int facing;
};

class BTRegenSkillEffect : public BTTargetedEffect
{
 public:
  BTRegenSkillEffect(int t, int x, int s, int m, int g, int trgt, int sk, const BTDice& u);

  virtual int maintain(BTDisplay &d, BTCombat *combat);

  int skill;
  BTDice use;
};

class BTPushEffect : public BTTargetedEffect
{
 public:
  BTPushEffect(int t, int x, int s, int m, int g, int trgt, int dis);

  virtual int maintain(BTDisplay &d, BTCombat *combat);

  int distance;
};

class BTAttackRateBonusEffect : public BTTargetedEffect
{
 public:
  BTAttackRateBonusEffect(int t, int x, int s, int m, int g, int trgt, int b);

  virtual int apply(BTDisplay &d, BTCombat *combat, int g = BTTARGET_NONE, int trgt = BTTARGET_INDIVIDUAL);
  virtual void finish(BTDisplay &d, BTCombat *combat, int g = BTTARGET_NONE, int trgt = BTTARGET_INDIVIDUAL);

  int bonus;
};

class BTRegenManaEffect : public BTTargetedEffect
{
 public:
  BTRegenManaEffect(int t, int x, int s, int m, int g, int trgt, const BTDice& sp);

  virtual int maintain(BTDisplay &d, BTCombat *combat);

  BTDice mana;
};

class BTSaveBonusEffect : public BTTargetedEffect
{
 public:
  BTSaveBonusEffect(int t, int x, int s, int m, int g, int trgt, int b);

  virtual int apply(BTDisplay &d, BTCombat *combat, int g = BTTARGET_NONE, int trgt = BTTARGET_INDIVIDUAL);
  virtual void finish(BTDisplay &d, BTCombat *combat, int g = BTTARGET_NONE, int trgt = BTTARGET_INDIVIDUAL);

  int bonus;
};

class BTScrySightEffect : public BTBaseEffect
{
 public:
  BTScrySightEffect(int t, int x, int s, int m);

  virtual int maintain(BTDisplay &d, BTCombat *combat);
};

class BTSpellBindEffect : public BTResistedEffect
{
 public:
  BTSpellBindEffect(int t, int x, int s, int m, int g, int trgt);

  virtual int apply(BTDisplay &d, BTCombat *combat, int g = BTTARGET_NONE, int trgt = BTTARGET_INDIVIDUAL);
  virtual void finish(BTDisplay &d, BTCombat *combat, int g = BTTARGET_NONE, int trgt = BTTARGET_INDIVIDUAL);
};

#endif

