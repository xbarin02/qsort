#ifndef BTREE_H_8923dfklajs984jfa9s8haf
#define BTREE_H_8923dfklajs984jfa9s8haf

#define bt_key_t int
#define bt_value_t int
#define bt_key_cmp(a,b) ((a)-(b))

typedef struct bt_node_s bt_node_t;
typedef struct bt_root_s bt_root_t;

struct bt_node_s {
  bt_key_t key;
  bt_value_t value;
  bt_node_t *left;
  bt_node_t *right;
  bt_node_t *parent;
};

bt_node_t *bt_new(bt_key_t key, bt_value_t value);
bt_node_t *bt_set(bt_node_t *T, bt_key_t key, bt_value_t value);
bt_node_t *bt_get(bt_node_t *T, bt_key_t key);
bt_node_t *bt_max(bt_node_t *T);
bt_node_t *bt_min(bt_node_t *T);
bt_node_t *bt_next(bt_node_t *x);
bt_node_t *bt_prev(bt_node_t *x);
void bt_del(bt_node_t *x);

#endif
