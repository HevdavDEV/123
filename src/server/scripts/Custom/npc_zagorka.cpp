#include "ScriptMgr.h"
#include "ScriptedCreature.h"


enum Spells
{
    SPELL_STATIC_DISRUPTION     = 43622,
    SPELL_STATIC_VISUAL         = 45265,
    SPELL_CALL_LIGHTNING        = 43661, // Missing timer
    SPELL_GUST_OF_WIND          = 43621,
    SPELL_ELECTRICAL_STORM      = 43648,
    SPELL_BERSERK               = 45078,
    SPELL_ELECTRICAL_OVERLOAD   = 43658,
    SPELL_EAGLE_SWOOP           = 44732,
    SPELL_ZAP                   = 43137,
    SPELL_SAND_STORM            = 25160
};

enum Says
{
    SAY_AGGRO                   = 0,
    SAY_SUMMON                  = 1,
    SAY_INTRO                   = 2, // Not used in script
    SAY_ENRAGE                  = 3,
    SAY_KILL                    = 4,
    SAY_DEATH                   = 5
};

enum Misc
{
    NPC_SOARING_EAGLE           = 24858,
    SE_LOC_X_MAX                = 400,
    SE_LOC_X_MIN                = 335,
    SE_LOC_Y_MAX                = 1435,
    SE_LOC_Y_MIN                = 1370
};

enum Events
{
    EVENT_STATIC_DISRUPTION     = 1,
    EVENT_GUST_OF_WIND          = 2,
    EVENT_CALL_LIGHTNING        = 3,
    EVENT_ELECTRICAL_STORM      = 4,
    EVENT_RAIN                  = 5,
    EVENT_SUMMON_EAGLES         = 6,
    EVENT_STORM_SEQUENCE        = 7,
    EVENT_ENRAGE                = 8
};

class boss_akilzon : public CreatureScript
{
    public:
        boss_akilzon() : CreatureScript("boss_akilzon") { }

        struct npc_akilzon_eagleAI : public ScriptedAI
        {
            npc_akilzon_eagleAI(Creature* creature) : ScriptedAI(creature) { }

            uint32 EagleSwoop_Timer;
            bool arrived;
            uint64 TargetGUID;

            void Reset() OVERRIDE
            {
                EagleSwoop_Timer = urand(3000, 8000);
                arrived = true;
                TargetGUID = 0;
                me->SetDisableGravity(true);
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                DoZoneInCombat();
            }

            void MoveInLineOfSight(Unit* /*who*/) OVERRIDE { }


            void MovementInform(uint32, uint32) OVERRIDE
            {
                arrived = true;
                if (TargetGUID)
                {
                    if (Unit* target = Unit::GetUnit(*me, TargetGUID))
                        DoCast(target, SPELL_EAGLE_SWOOP, true);
                    TargetGUID = 0;
                    me->SetSpeed(MOVE_RUN, 1.2f);
                    EagleSwoop_Timer = urand(3000, 8000);
                }
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (EagleSwoop_Timer <= diff)
                    EagleSwoop_Timer = 0;
                else
                    EagleSwoop_Timer -= diff;

                if (arrived)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        float x, y, z;
                        if (EagleSwoop_Timer)
                        {
                            x = target->GetPositionX() + irand(-10, 10);
                            y = target->GetPositionY() + irand(-10, 10);
                            z = target->GetPositionZ() + urand(10, 15);
                            if (z > 95)
                                z = 95.0f - urand(0, 5);
                        }
                        else
                        {
                            target->GetContactPoint(me, x, y, z);
                            z += 2;
                            me->SetSpeed(MOVE_RUN, 3.0f);
                            TargetGUID = target->GetGUID();
                        }
                        me->GetMotionMaster()->MovePoint(0, x, y, z);
                        arrived = false;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_akilzon_eagleAI(creature);
        }
};

void AddSC_boss_akilzon()
{
    new boss_akilzon();
}