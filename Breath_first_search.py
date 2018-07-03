#breath_first search
from collections import deque

def person_judge(person):
    return person[-1] == 'm'

def search_person():

    graph = { }
    graph['me'] = ['alice', 'bob', 'claire']
    graph['bob'] = ['anuj', 'peggy']
    graph['alice'] = ['peggy']
    graph['claire'] = ['thom', 'jonny']
    graph['anuj'] = []
    graph['peggy'] = []
    graph['thom'] = []
    graph['jonny'] = []

    search_queue = deque()
    search_queue += graph['me']
    searched = []
    
    while search_queue:
        person = search_queue.popleft()
        if person not in searched:
            if person_judge(person):
                print(person)
                return True
            else:
                search_queue += graph[person]
                searched.append(person)
    return False

search_person()
