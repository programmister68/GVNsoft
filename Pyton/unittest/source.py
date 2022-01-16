import sys

class Tree:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.key = key
        self.data = None


class BST(Tree):
    def insert(self, key):
        if self.key == None:
            self.key = key
        else:
            if key < self.key:
                if self.left is None:
                    self.left = BST(key)
                else:
                    self.left.insert(key)

            elif (key > self.key):
                if self.right is None:
                    self.right = BST(key)
                else:
                    self.right.insert(key)
            else:
                print("Dublicate data")

    def get_tree(
            self):
        if self.key == None:
            print("Empty Data")
            return self

        if self.left is not None:
            self.left.get_tree()

            if self.key != None:
                print(self.key, ' ', end='')

            if self.right is not None:
                self.right.get_tree()

        else:
            if self.key != None:
                print(self.key, ' ', end='')

            if self.right is not None:
                self.right.get_tree()

    def delete(self, key, dictionary=None):
        if self.key == None:
            return self

        if self.key != key:
            if key < self.key:
                self.left = self.left.delete(key)
            else:
                self.right = self.right.delete(key)

        else:
            if self.right == None:
                temp = self.left
                if dictionary != None:
                    if dictionary.key == key and self.left == None:
                        self.key = None
                        return self
                else:

                    return temp
            if self.left == None:
                temp = self.right
                del self
                return temp

            link = self.right.search_min()
            temp = link.key
            self.delete(
                link.key)
            self.key = temp
        return self

    def search_min(self):
        if self.left != None:
            return self.left.search_min()
        return self


if __name__ == '__main__':
    dictionary = BST(None)
