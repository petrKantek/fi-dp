# Define the lists
py = ['CWE-79', 'CWE-78', 'CWE-20', 'CWE-22', 'CWE-352', 'CWE-287', 'CWE-502', 'CWE-77', 'CWE-918', 'CWE-306', 'CWE-94', 'CWE-863', 'CWE-434', 'CWE-862']
cpp = ['CWE-787', 'CWE-79', 'CWE-89', 'CWE-416', 'CWE-78', 'CWE-20', 'CWE-125', 'CWE-22', 'CWE-476', 'CWE-287', 'CWE-190', 'CWE-77', 'CWE-119', 'CWE-362', 'CWE-269']
csharp = ['CWE-787', 'CWE-79', 'CWE-89', 'CWE-78', 'CWE-20', 'CWE-22', 'CWE-352', 'CWE-434', 'CWE-862', 'CWE-287', 'CWE-190', 'CWE-502', 'CWE-77', 'CWE-119', 'CWE-798', 'CWE-918', 'CWE-362', 'CWE-94']
js = ['CWE-79', 'CWE-89', 'CWE-78', 'CWE-20', 'CWE-22', 'CWE-352', 'CWE-434', 'CWE-862', 'CWE-476', 'CWE-287', 'CWE-502', 'CWE-77', 'CWE-798', 'CWE-918', 'CWE-362', 'CWE-269', 'CWE-94']

# Create sets from the lists
py_set = set(py)
cpp_set = set(cpp)
csharp_set = set(csharp)
js_set = set(js)

# Calculate the number of common elements
common_py_cpp = len(py_set.intersection(cpp_set))
common_py_csharp = len(py_set.intersection(csharp_set))
common_py_js = len(py_set.intersection(js_set))
common_cpp_csharp = len(cpp_set.intersection(csharp_set))
common_cpp_js = len(cpp_set.intersection(js_set))
common_csharp_js = len(csharp_set.intersection(js_set))

# Display the results
print(f'Common elements between Py and C++: {common_py_cpp}')
print(f'Common elements between Py and C#: {common_py_csharp}')
print(f'Common elements between Py and Js: {common_py_js}')
print(f'Common elements between C++ and C#: {common_cpp_csharp}')
print(f'Common elements between C++ and Js: {common_cpp_js}')
print(f'Common elements between C# and Js: {common_csharp_js}')
print(len(py_set.union(cpp_set).union(csharp_set).union(js_set)))
