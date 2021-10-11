"""
It creates a dictionary from a json array and includes a example.
"""


def addElementsToDict(collection, dictionary, key):
    """
    Its recibes a collection of json, a dictionary and a key that is used as criterio to build the dictionary.
    """
    for element in collection:
        if element[key] not in dictionary:
            dictionary[element[key]] = element


# Example
myObjects = [
    {"id": 1, "code": "A001", "name": "John Doe", "value": 53},
    {"id": 2, "code": "A002", "name": "Jane Doe", "value": 86}
]

myDictionary = {}
addElementsToDict(myObjects, myDictionary, "code")
print(myDictionary)
