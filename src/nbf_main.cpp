/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>
 * released under GNU AGPL v3 license
 * https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "GlobalScript.h"
#include "SpellScript.h"

enum NBFMisc
{
    SPELL_MAGIC_ROOSTER = 65917
};

class NbfGlobalScript : public GlobalScript
{
public:
    NbfGlobalScript() : GlobalScript("NbfGlobalScript") { }

    void OnLoadSpellCustomAttr(SpellInfo* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_MAGIC_ROOSTER:
            {
                spellInfo->Attributes &= ~SPELL_ATTR0_ALLOW_WHILE_MOUNTED;
                break;
            }

            default:
                break;
        }
    }
};

void non_blizzlike_fixesScripts()
{
    new NbfGlobalScript();
}
