# RPG Combat Kata

## Sources

- https://github.com/ardalis/kata-catalog/blob/main/katas/RPG%20Combat.md
- https://sammancoaching.org/kata_descriptions/rpg_combat.html

## Requirements

- [X] Characters can be created
- [X] New characters have 1000 Health
- [X] New characters start from level 1
- [X] Characters can be Alive or Dead
- [X] New characters are Alive
- [X] Characters can Deal 1 Damage to Characters
- [X] Damage is subtracted from Health
- [X] When damage received exceeds current Health, Health becomes 0 and the character is now Dead
- [X] A Character can Heal a Character of 1 Health
- [X] Dead characters cannot be healed
- [X] Healing cannot raise health above 1000
- [X] A Character cannot Deal Damage to itself
- [X] If the target is 5 or more Levels above the attacker, Damage is reduced by 50%
- [X] If the target is 5 or more Levels below the attacker, Damage is increased by 50%
- [X] Newly created Characters must have a Position
- [X] Characters have an attack Max Range
- [X] Melee fighters have a range of 2 meters
- [X] Ranged fighters have a range of 20 meters
- [ ] Characters must be in range to deal damage to a target
- [ ] Factions can be created
- [ ] Characters may belong to one or more Factions
- [ ] New Characters belong to no Faction
- [ ] A Character may Join one or more Factions
- [ ] A Character may Leave one or more Factions
- [ ] Players belonging to the same Faction are considered Allies
- [ ] Allies cannot Deal Damage to one another
- [ ] Allies can Heal one another
- [ ] Things can be created
- [ ] Newly created Things must have a name (e.g. "Tree")
- [ ] Newly created Things can have any Health > 1 (e.g. 2000)
- [ ] Newly created Things must have a Position
- [ ] Characters can damage Things which are in Range
- [ ] These things cannot be Healed and they do not Deal Damage
- [ ] These things do not belong to Factions: they are neutral
- [ ] When reduced to 0 Health, things are Destroyed
- [ ] Magical Objects can be created
- [ ] Magical Objects have Health
- [ ] The maximum amount of Health is fixed at the time the object is created
- [ ] When reduced to 0 Health, Magical Objects are Destroyed
- [ ] Magical Objects cannot be Healed by Characters
- [ ] Magical Objects do not belong to Factions; they are neutral
- [ ] Characters can hold one Magical Object
- [ ] Newly created Characters hold no Magical Object
- [ ] Characters can gain health from a Healing Magical Object
- [ ] Characters can gain any amount of health from the Object, up to its maximum and theirs
- [ ] Healing Magical Objects cannot deal Damage
- [ ] Characters can deal Damage by using a Magical Weapon
- [ ] These Magical Objects deal a fixed amount of damage when they are used
- [ ] The amount of damage is fixed at the time the weapon is created
- [ ] Every time the weapon is used, its Health is reduced by 1
- [ ] Magical Weapons cannot give Health to a Character
- [ ] Destroyed Magical Weapons are ineffective
- [ ] Level 1 Characters that survive 1000 damage points gain a level (this may be counted over several battles)
- [ ] A character cannot gain a level while receiving damage, it happens directly afterwards (if the player is still alive)
- [ ] Level 2 Characters need to survive an additional 2000 damage points to gain a level
- [ ] Level 3 Characters need to survive an additional 3000, and so on
- [ ] Level 1 Characters that have ever been part of 3 distinct factions gain a level
- [ ] Level 2 Characters need to join an additional 3 distinct factions to gain a level
- [ ] Level 3 Characters need to join an additional 3, and so on
- [ ] From Level 6 on, a Character maximum Health is 1500
- [ ] The maximum Level for Characters is 10
