#include <stack>
#include <iostream>

template<typename Tp>
class FixedAllocator {

 public:
    explicit FixedAllocator(std::uint64_t page_size):
                page_allocator_(page_size), page_size_(page_size) {
    }

    Tp* Allocate() {
        Tp* ptr;
        if (container.empty()) {
            ptr = static_cast<Tp*>(page_allocator_.Allocate());
            for (size_t i = 0; i < page_size_; i++) {
                ptr += i;
                container.push(ptr);
            }
        }
        ptr = container.top();
        container.pop();
        return ptr;
    }

    void Deallocate(Tp* p) {
        container.push(p);
    }

    const PageAllocator& InnerAllocator() const noexcept {
        return page_allocator_;
    }

 private:
    std::stack <Tp*> container;
    PageAllocator page_allocator_;
    size_t page_size_;
};

