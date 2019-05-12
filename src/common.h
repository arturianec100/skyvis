#ifndef COMMON_H
#define COMMON_H

#define SAFE_DELETE(PTR) if (PTR != nullptr) { delete PTR; PTR = nullptr; }

#endif // COMMON_H
