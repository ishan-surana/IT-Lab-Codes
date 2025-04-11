from math import log2
data = {
    'Outlook': ['Sunny', 'Sunny', 'Overcast', 'Rain', 'Rain', 'Rain', 'Overcast', 'Sunny', 'Sunny', 'Rain', 'Sunny', 'Overcast', 'Overcast', 'Rain'], 
    'Temperature': ['Hot', 'Hot', 'Hot', 'Mild', 'Cool', 'Cool', 'Cool', 'Mild', 'Cool', 'Mild', 'Mild', 'Mild', 'Hot', 'Mild'], 
    'Humidity': ['High', 'High', 'High', 'High', 'Normal', 'Normal', 'Normal', 'High', 'Normal', 'Normal', 'Normal', 'High', 'Normal', 'High'], 
    'Wind': ['Weak', 'Strong', 'Weak', 'Weak', 'Weak', 'Strong', 'Strong', 'Weak', 'Weak', 'Weak', 'Strong', 'Strong', 'Weak', 'Strong'], 
    'Play Tennis': ['No', 'No', 'Yes', 'Yes', 'Yes', 'No', 'Yes', 'No', 'Yes', 'Yes', 'Yes', 'Yes', 'Yes', 'No']
}
len_data = len(data['Outlook'])

def ig(data, labels, feature):
    values = data[feature]
    uniques = list(set(values))
    entropy = 0
    total = len(labels)

    for val in uniques:
        relevant = [(v, l) for v, l in zip(values, labels) if v == val]
        sub_labels = [l for v, l in relevant]
        yes_count = sub_labels.count('Yes')
        no_count = sub_labels.count('No')

        yes_entropy = -(yes_count/len(sub_labels))*log2(yes_count/len(sub_labels)) if yes_count>0 else 0
        no_entropy = -(no_count/len(sub_labels))*log2(no_count/len(sub_labels)) if no_count>0 else 0
        entropy += (len(sub_labels)/total)*(yes_entropy + no_entropy)

    yes_count = labels.count('Yes')
    no_count = labels.count('No')
    yes_entropy = -(yes_count/total)*log2(yes_count/total) if yes_count>0 else 0
    no_entropy = -(no_count/total)*log2(no_count/total) if no_count>0 else 0
    total_entropy = yes_entropy + no_entropy
    return total_entropy - entropy

def build_tree(indices, features):
    labels = [data['Play Tennis'][i] for i in indices]
    if len(list(set(labels))) == 1:
        return labels[0]
    
    best_feature = features[0]
    best_ig = ig(data, labels, best_feature)
    for feature in features:
        gain = ig(data, labels, feature)
        if gain > best_ig:
            best_ig = gain
            best_feature = feature

    tree = {best_feature: {}}
    values = set([data[best_feature][i] for i in indices])
    for val in values:
        sub_indices = [i for i in indices if data[best_feature][i] == val]
        new_features = [f for f in features if f != best_feature]
        tree[best_feature][val] = build_tree(sub_indices, new_features)

    return tree

features = [i for i in data if i != 'Play Tennis']
indices = list(range(len(data['Play Tennis'])))
tree = build_tree(indices, features)
print(tree)

def classify(tree, sample):
    if tree in ["Yes", "No"]:
        return tree
    feature = list(tree.keys())[0]
    feature_value = sample[feature]
    return classify(tree[feature][feature_value], sample)

new_samples = [
    {'Outlook': 'Sunny', 'Temperature': 'Hot', 'Humidity': 'High', 'Wind': 'Weak'},
    {'Outlook': 'Overcast', 'Temperature': 'Mild', 'Humidity': 'Normal', 'Wind': 'Strong'},
    {'Outlook': 'Rain', 'Temperature': 'Cool', 'Humidity': 'Normal', 'Wind': 'Weak'}
]

for i in range(len(new_samples)):
    result = classify(tree, new_samples[i])
    print(f"Sample {i+1} -> Play Tennis: {result}")