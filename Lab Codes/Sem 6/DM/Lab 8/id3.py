# data = [["Outlook","Temperature","Humidity","Wind","Play Tennis"],
# ["Sunny","Hot","High","Weak","No"],
# ["Sunny","Hot","High","Strong","No"],
# ["Overcast","Hot","High","Weak","Yes"],
# ["Rain","Mild","High","Weak","Yes"],
# ["Rain","Cool","Normal","Weak","Yes"],
# ["Rain","Cool","Normal","Strong","No"],
# ["Overcast","Cool","Normal","Strong","Yes"],
# ["Sunny","Mild","High","Weak","No"],
# ["Sunny","Cool","Normal","Weak","Yes"],
# ["Rain","Mild","Normal","Weak","Yes"],
# ["Sunny","Mild","Normal","Strong","Yes"],
# ["Overcast","Mild","High","Strong","Yes"],
# ["Overcast","Hot","Normal","Weak","Yes"],
# ["Rain","Mild","High","Strong","No"]]

# print([[i[j] for i in data] for j in range(len(data[0]))])

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

        yes_entropy = -(yes_count/len(sub_labels))*log2(yes_count/len(sub_labels)) if yes_count > 0 else 0
        no_entropy = -(no_count/len(sub_labels))*log2(no_count/len(sub_labels)) if no_count > 0 else 0
        entropy += (len(sub_labels)/total)*(yes_entropy + no_entropy)

    yes_vals = labels.count('Yes')
    no_vals = labels.count('No')
    total_entropy = 0
    if yes_vals > 0:
        total_entropy -= (yes_vals / total) * log2(yes_vals / total)
    if no_vals > 0:
        total_entropy -= (no_vals / total) * log2(no_vals / total)

    return total_entropy - entropy

# best_feature = 'Outlook'
# best_ig = ig(data['Outlook'])
# for i, j in data.items():
#     print(f"{i}: {ig(j)}")
#     if i!='Play Tennis' and ig(j) > best_ig:
#         best_feature = i
#         best_ig = ig(j)
# print("Best feature:", best_feature)

def majority(indices):
    yes = sum(1 for i in indices if data['Play Tennis'][i] == 'Yes')
    no = sum(1 for i in indices if data['Play Tennis'][i] == 'No')
    return 'Yes' if yes >= no else 'No'

def build_tree(indices, features):
    labels = [data['Play Tennis'][i] for i in indices]
    if labels.count(labels[0]) == len(labels):
        return labels[0]
    if not features:
        return majority(indices)
    
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
        sub_labels = [data['Play Tennis'][i] for i in sub_indices]
        if best_feature == 'Outlook' and val == 'Sunny':
            print("\n🟡 DEBUG: Branch where Outlook == Sunny")
            print("Examples:")
            for i in sub_indices:
                row = {f: data[f][i] for f in data}
                print(f"  {row}, Label = {labels[i]}")

            print("Info Gains for Sunny subset:")
            for f in data:
                if f != best_feature:
                    print(f"  IG({f}) = {ig(data, sub_labels, f):.5f}")

        if not sub_indices:
            tree[best_feature][val] = majority(indices)
        else:
            new_features = [f for f in features if f != best_feature]
            tree[best_feature][val] = build_tree(sub_indices, new_features)

    return tree

# Initial call
features = [f for f in data if f != 'Play Tennis']
indices = list(range(len(data['Play Tennis'])))
tree = build_tree(indices, features)
print(tree)
# # Print
# import json
# print(json.dumps(tree, indent=2))
