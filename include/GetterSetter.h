#pragma once
#define DEFINE_GETTER(type, name) \
    type get_##name() const { return name; }

#define DEFINE_SETTER(type, name) \
    void set_##name(type value) { name = value; }

#define DEFINE_GETTER_SETTER(type, name) \
    DEFINE_GETTER(type, name)            \
    DEFINE_SETTER(type, name)
