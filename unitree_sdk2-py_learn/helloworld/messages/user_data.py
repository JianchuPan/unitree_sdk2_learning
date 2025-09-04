from dataclasses import dataclass
from cyclonedds.idl import IdlStruct


# This class defines user data consisting of a float data and a string data
@dataclass
class UserDefineData(IdlStruct, typename="UserData"):
    string_data: str
    float_data: float
