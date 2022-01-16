import unittest

from source import BST # source - название основного файла, BST - функция


class TestBST(unittest.TestCase):
    def setUp(self, key=None):
        self.bst = BST(key)

class Test_Insert(TestBST):
    def many_insert(self, a):
        for num in a:
            self.bst.insert(num)

    def test_create_object_with_key(self):
        link = BST(10)
        self.assertEqual(link.key, 10)

    def test_insert_root(self):
        self.bst.insert(1)
        self.assertEqual(self.bst.key, 1)

    def test_insert_right(self):
        self.many_insert(1, 2)
        self.assertEqual(self.bst.right.key, 2)

    def test_insert_left(self):
        self.bst.insert(3, -3)
        self.assertEqual(self.bst.left.key, -3)
