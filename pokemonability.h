#ifndef POKEMONABILITY_H
#define POKEMONABILITY_H

#define MAX_POKEMON     17
#define IDofBulbasaur   0
#define IDofCharmander  1
#define IDofHeracross   2
#define IDofJigglypuff  3
#define IDofJirachi     4
#define IDofLugia       5
#define IDofLuxio       6
#define IDofMachop      7
#define IDofMeowth      8
#define IDofOnix        9
#define IDofPangoro     10
#define IDofPikachu     11
#define IDofPolitoed    12
#define IDofPsyduck     13
#define IDofRaikou      14
#define IDofSquirtle    15
#define IDofZweilous    16

/*下方是需要修改的部分
**只需要修改数字
**格式为：“属性of宝可梦”
**每个宝可梦六个属性，依次是：
******移速:0.5为基本但偏慢的速度，建议以0.3为下限
******最大生命值：所给默认值略低，建议以70为下限
******价格（AbilityPoint）：200属于最基本的兵种，建议150为下限
******攻击力：所给的默认值偏高，建议范围为5~20
******攻速：暂时无法实现攻速机制，所以可以先不用管
******攻击距离：以40为近战距离
*/
#define SpeedofBulbasaur            1.0
#define MaxHPofBulbasaur            90
#define AbilityPointofBulbasaur		220
#define AttackAbilityofBulbasaur	7
#define AttackSpeedofBulbasaur		4
#define AttackDistanceofBulbasaur   70

#define SpeedofCharmander            1.0
#define MaxHPofCharmander            95
#define AbilityPointofCharmander     230
#define AttackAbilityofCharmander    8
#define AttackSpeedofCharmander      4
#define AttackDistanceofCharmander   80

#define SpeedofHeracross            0.7
#define MaxHPofHeracross            130
#define AbilityPointofHeracross     300
#define AttackAbilityofHeracross    13
#define AttackSpeedofHeracross      4
#define AttackDistanceofHeracross   40

#define SpeedofJigglypuff            1.0
#define MaxHPofJigglypuff            90
#define AbilityPointofJigglypuff     200
#define AttackAbilityofJigglypuff    6
#define AttackSpeedofJigglypuff      4
#define AttackDistanceofJigglypuff   110

#define SpeedofJirachi            1.1
#define MaxHPofJirachi            200
#define AbilityPointofJirachi     450
#define AttackAbilityofJirachi    19
#define AttackSpeedofJirachi      4
#define AttackDistanceofJirachi   140

#define SpeedofLugia            0.9
#define MaxHPofLugia            210
#define AbilityPointofLugia     450
#define AttackAbilityofLugia    18
#define AttackSpeedofLugia      4
#define AttackDistanceofLugia   140

#define SpeedofLuxio            0.5
#define MaxHPofLuxio            140
#define AbilityPointofLuxio     320
#define AttackAbilityofLuxio    14
#define AttackSpeedofLuxio      4
#define AttackDistanceofLuxio   70

#define SpeedofMachop            1.0
#define MaxHPofMachop            90
#define AbilityPointofMachop     230
#define AttackAbilityofMachop    8
#define AttackSpeedofMachop      4
#define AttackDistanceofMachop   100

#define SpeedofMeowth            1.1
#define MaxHPofMeowth            100
#define AbilityPointofMeowth     220
#define AttackAbilityofMeowth    6
#define AttackSpeedofMeowth      4
#define AttackDistanceofMeowth   100

#define SpeedofOnix            0.5
#define MaxHPofOnix            180
#define AbilityPointofOnix     360
#define AttackAbilityofOnix    16
#define AttackSpeedofOnix      4
#define AttackDistanceofOnix   50

#define SpeedofPangoro            0.5
#define MaxHPofPangoro            190
#define AbilityPointofPangoro     380
#define AttackAbilityofPangoro    17
#define AttackSpeedofPangoro      4
#define AttackDistanceofPangoro   70

#define SpeedofPikachu            1.0
#define MaxHPofPikachu            110
#define AbilityPointofPikachu     230
#define AttackAbilityofPikachu    6
#define AttackSpeedofPikachu      4
#define AttackDistanceofPikachu   80

#define SpeedofPolitoed            0.5
#define MaxHPofPolitoed            150
#define AbilityPointofPolitoed     290
#define AttackAbilityofPolitoed    11
#define AttackSpeedofPolitoed      4
#define AttackDistanceofPolitoed   100

#define SpeedofPsyduck            1.1
#define MaxHPofPsyduck            90
#define AbilityPointofPsyduck     180
#define AttackAbilityofPsyduck    5
#define AttackSpeedofPsyduck      4
#define AttackDistanceofPsyduck   45

#define SpeedofRaikou            0.8
#define MaxHPofRaikou            160
#define AbilityPointofRaikou     320
#define AttackAbilityofRaikou    14
#define AttackSpeedofRaikou      4
#define AttackDistanceofRaikou   75

#define SpeedofSquirtle            1.0
#define MaxHPofSquirtle            80
#define AbilityPointofSquirtle     240
#define AttackAbilityofSquirtle    7
#define AttackSpeedofSquirtle      4
#define AttackDistanceofSquirtle   110

#define SpeedofZweilous            0.7
#define MaxHPofZweilous            150
#define AbilityPointofZweilous     320
#define AttackAbilityofZweilous    12
#define AttackSpeedofZweilous      4
#define AttackDistanceofZweilous   80


#endif // POKEMONABILITY_H
