#ifndef FREE_FUNCTION_H
#define FREE_FUNCTION_H

int is_value_max(int value,int max_value,int hope_value){  //判断值是否超过最大值，并返回最大值或希望值
	if(value>=max_value){

		value=hope_value;
	}
	return value;

}

int is_value_max_for_modulus(int value,int max_value,int hope_modulus){  //判断值是否超过最大值，并返回最大值或希望值

    if(value>=max_value){
        value=value%hope_modulus;
    }
    return value;

}

int is_value_min(int value,int min_value,int hope_value){  //判断值是否超过最大值，并返回最大值或希望值
	if(value<=min_value){

		value=hope_value;
	}
	return value;

}
