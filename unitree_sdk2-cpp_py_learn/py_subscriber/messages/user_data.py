from dataclasses import dataclass
from cyclonedds.idl import IdlStruct


# This class defines user data consisting of a float data and a string data
@dataclass # 用 @dataclass 简化类定义，字段直接对应 IDL 字段，无需手动写 getter/setter
class UserData(IdlStruct, typename="UserDataModule.UserData"): # 注意与 C++ IDL 的模块名匹配，# 格式：module名.结构体名
    string_data: str
    float_data: float # py中float必须用C++中的double进行对应
