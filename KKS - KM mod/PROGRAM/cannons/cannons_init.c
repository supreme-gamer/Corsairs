void InitBaseCannons_CalcSpeedV0(ref rCannon, float fFireRange)
{
	rCannon.FireRange = fFireRange;
	rCannon.SpeedV0 = sqrt(fFireRange * 9.81 / sin( 2.0 * MakeFloat(rCannon.FireAngMax)) );
}

void InitCannons()
{
	ref rCannon;
	
	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS3]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber3";
	rCannon.picture = "cannons5";
	rCannon.Sound = "cannon_fire_cannon_3";
	rCannon.caliber = 3;
	rCannon.ReloadTime = 8;
	rCannon.Cost = 500;
	rCannon.Weight = 2;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 4.0;
	rCannon.hp = 50.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,250.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS6]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber6";
	rCannon.picture = "cannons5";
	rCannon.Sound = "cannon_fire_cannon_6";
	rCannon.caliber = 6;
	rCannon.ReloadTime = 10;
	rCannon.Cost = 1000;
	rCannon.Weight = 4;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 8.0;
	rCannon.hp = 60.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,300.0);
	
	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS12]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber12";
	rCannon.picture = "cannons5";
	rCannon.Sound = "cannon_fire_cannon_12";
	rCannon.caliber = 12;
	rCannon.ReloadTime = 15;
	rCannon.Cost = 1500;
	rCannon.Weight = 8;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 12.0;
	rCannon.hp = 89.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,450.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS16]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber16";
	rCannon.picture = "cannons6";
	rCannon.Sound = "cannon_fire_cannon_16";
	rCannon.caliber = 16;
	rCannon.ReloadTime = 20;
	rCannon.Cost = 2000;
	rCannon.Weight = 12;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 16.0;
	rCannon.hp = 86.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,500.0);
		
	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS20]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber20";
	rCannon.picture = "cannons7";
	rCannon.Sound = "cannon_fire_cannon_20";
	rCannon.caliber = 20;
	rCannon.ReloadTime = 25;
	rCannon.Weight = 15;
	rCannon.Cost = 2500;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 20.0;
	rCannon.hp = 83.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,550.0);
	
	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS24]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber24";
	rCannon.picture = "cannons7";
	rCannon.Sound = "cannon_fire_cannon_24";
	rCannon.caliber = 24;
	rCannon.ReloadTime = 30;
	rCannon.Weight = 18;
	rCannon.Cost = 3000;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 24.0;
	rCannon.hp = 80.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,600.0);
	
	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS32]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.caliber = 32;
	rCannon.name = "caliber32";
	rCannon.picture = "cannons8";
	rCannon.Sound = "cannon_fire_cannon_32";
	rCannon.ReloadTime = 40;
	rCannon.Cost = 4000;
	rCannon.Weight = 24;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.45;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 32.0;
	rCannon.hp = 75.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,700.0);
	
	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS36]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.caliber = 36;
	rCannon.name = "caliber36";
	rCannon.picture = "cannons8";
	rCannon.Sound = "cannon_fire_cannon_36";
	rCannon.ReloadTime = 50;
	rCannon.Cost = 5000;
	rCannon.Weight = 28;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 36.0;
	rCannon.TradeOff = true;
	rCannon.hp = 70.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,750.0); 
	
	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS42]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.caliber = 42;
	rCannon.name = "caliber42";
	rCannon.picture = "cannons11";
	rCannon.Sound = "cannon_fire_cannon_42";
	rCannon.ReloadTime = 60;
	rCannon.Cost = 10000;
	rCannon.Weight = 35;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.45;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 42.0;
	rCannon.TradeOff = true;
	rCannon.hp = 65.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,800.0);
	
	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS48]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.caliber = 48;
	rCannon.name = "caliber48";
	rCannon.picture = "cannons12";
	rCannon.Sound = "cannon_fire_cannon_48";
	rCannon.ReloadTime = 70;
	rCannon.Cost = 25000;
	rCannon.Weight = 50;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.45;
	rCannon.DamageMultiply = 80.0;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 80.0;
	rCannon.TradeOff = true;
	rCannon.hp = 80.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,1000.0);
	
    makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS8]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.name = "caliber8";
	rCannon.picture = "cannons1";
	rCannon.Sound = "cannon_fire_culverine_8";
	rCannon.caliber = 8;
	rCannon.ReloadTime = 35;
	rCannon.Cost = 2400;
	rCannon.Weight = 12;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 15.0;
	rCannon.hp = 93.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,500.0);
	
	makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS18]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.name = "caliber18";
	rCannon.picture = "cannons2";
	rCannon.Sound = "cannon_fire_culverine_18";
	rCannon.caliber = 18;
	rCannon.ReloadTime = 50;
	rCannon.Cost = 3600;
	rCannon.Weight = 24;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 25.0;
	rCannon.hp = 95.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,700.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS36]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.caliber = 36;
	rCannon.name = "caliber36";
	rCannon.picture = "cannons4";
	rCannon.Sound = "cannon_fire_culverine_36";
	rCannon.ReloadTime = 70;
	rCannon.Cost = 12000;
	rCannon.Weight = 50;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.45;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 45.0;
	rCannon.TradeOff = true;
	rCannon.hp = 90.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,900.0);
}