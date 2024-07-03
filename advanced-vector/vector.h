#pragma once
/*
 * Реализуйте следующие методы класса Vector:
 * 1) Конструктор по умолчанию. Инициализирует вектор нулевого размера и вместимости. Не выбрасывает исключений.
 * Алгоритмическая сложность: O(1).
 * 2) Конструктор, который создаёт вектор заданного размера. Вместимость созданного вектора равна его размеру,
 * а элементы проинициализированы значением по умолчанию для типа T. Алгоритмическая сложность: O(размер вектора).
 * 3) Копирующий конструктор. Создаёт копию элементов исходного вектора. Имеет вместимость, равную размеру исходного вектора,
 * то есть выделяет память без запаса. Алгоритмическая сложность: O(размер исходного вектора).
 * 4) Деструктор. Разрушает содержащиеся в векторе элементы и освобождает занимаемую ими память.
 * Алгоритмическая сложность: O(размер вектора).
 * 5) Метод void Reserve(size_t capacity). Резервирует достаточно места, чтобы вместить количество элементов, равное capacity.
 * Если новая вместимость не превышает текущую, метод не делает ничего. Алгоритмическая сложность: O(размер вектора).
 *
 * Сделайте конструкторы класса Vector и метод Reserve устойчивыми к возникновению исключений.
 * Исключения не должны приводить к утечкам памяти или неопределённому поведению.
 * Метод Reserve в случае возникновения исключения должен оставлять вектор в прежнем состоянии.
 *
 * Упростите конструкторы, деструктор и метод Reserve класса Vector, применив класс RawMemory.
 * Функционал класса Vector должен остаться без изменений.
 *
 * Используйте uninitialized_*-функции и функции std::destroy_*, чтобы упростить конструкторы,
 * деструктор и метод Reserve класса Vector.
 * Метод Reserve должен перемещать элементы, если их конструктор перемещения не выбрасывает исключений или они
 * не имеют конструктора копирования.
 *
 * Реализуйте в классе Vector операции:
 * 6) Метод Swap, выполняющий обмен содержимого вектора с другим вектором. Операция должна иметь сложность O(1)
 * и не выбрасывать исключений.
 * 7) Перемещающий конструктор. Выполняется за O(1) и не выбрасывает исключений.
 * 8) Оператор копирующего присваивания. Выполняется за O(N), где N — максимум из размеров векторов, участвующих в операции.
 * 9) Оператор перемещающего присваивания. Выполняется за O(1) и не выбрасывает исключений.
 *
 * Реализуйте в классе Vector методы:
 * 10) Resize,
 * 11) PushBack,
 * 12) PopBack.
 * Обе версии метода PushBack должны поддерживать корректную вставку элемента вектора в конец этого же вектора.
 * Метод PushBack должен предоставлять строгую гарантию безопасности исключений, когда выполняется любое из условий:
 * - мove-конструктор у типа T объявлен как noexcept;
 * - тип T имеет публичный конструктор копирования.
 * Если у типа T нет конструктора копирования и move-конструктор может выбрасывать исключения, метод PushBack
 * должен предоставлять базовую гарантию безопасности исключений.
 * Сложность метода PushBack должна быть амортизированной константой.
 * Метод PopBack не должен выбрасывать исключений при вызове у непустого вектора.
 * При вызове PopBack у пустого вектора поведение неопределённо. Метод PopBack должен иметь сложность O(1).
 * Метод Resize должен предоставлять строгую гарантию безопасности исключений, когда выполняется любое из условий:
 * - move-конструктор у типа T объявлен как noexcept;
 * - тип T имеет публичный конструктор копирования.
 * Если у типа T нет конструктора копирования и move-конструктор может выбрасывать исключения, метод Resize
 * может предоставлять базовую или строгую гарантию безопасности исключений.
 *
 * Реализуйте в классе Vector метод:
 * 13) EmplaceBack, добавляющий новый элемент в конец вектора.
 * Созданный объект должен быть сконструирован с использованием аргументов метода EmplaceBack.
 * Метод EmplaceBack должен предоставлять строгую гарантию безопасности исключений, когда выполняется любое из условий:
 * - move-конструктор у типа T объявлен как noexcept;
 * - тип T имеет публичный конструктор копирования.
 * Если у типа T нет конструктора копирования и move-конструктор может выбрасывать исключения, метод EmplaceBack
 * должен предоставлять базовую гарантию безопасности исключений.
 * Сложность метода EmplaceBack должна быть амортизированной константой.
 *
 * Реализуйте в классе Vector методы:
 * 14) Insert,
 * 15) Emplace
 * 16) Erase
 * 17) begin,
 * 18) cbegin,
 * 19) end,
 * 20) cend.
 *
 * Методы Emplace и Erase, выполняя реаллокацию, должны перемещать элементы, а не копировать, если действительно любое из условий:
 * - тип T имеет noexcept-конструктор перемещения;
 * - тип T не имеет конструктора копирования.
 * Если при вставке происходит реаллокация, ожидается ровно Size() перемещений или копирований существующих элементов.
 * Сам вставляемый элемент должен копироваться либо перемещаться в зависимости от версии метода Insert.
 * Вызов Insert и Emplace, не требующий реаллокации, должен перемещать ровно end()-it_pos существующих элементов плюс
 * одно перемещение элемента из временного объекта в вектор.
 * Методы Insert и Emplace при вставке элемента в конец вектора должны обеспечивать строгую гарантию безопасности исключений,
 * когда выполняется любое из условий:
 * - шаблонный параметр T имеет конструктор копирования;
 * - шаблонный параметр T имеет noexcept-конструктор перемещения.
 * Если ни одно из этих условий не выполняется либо элемент вставляется в середину или начало вектора,
 * методы Insert и Emplace должны обеспечивать базовую гарантию безопасности исключений.
 * Метод Erase должен вызывать деструктор ровно одного элемента, а также вызывать оператор присваивания столько раз,
 * сколько элементов находится в векторе следом за удаляемым элементом.
 * Итератор it_pos, который задаёт позицию удаляемого элемента, должен указывать на существующий элемент вектора.
 * Передача в метод Erase итератора end(), невалидного итератора или итератора, полученного у другого вектора,
 * приводит к неопределённому поведению.
 */
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <memory>
#include <new>
#include <stdexcept>
#include <utility>

template <typename T>
class RawMemory {
public:
    RawMemory() = default;

    explicit RawMemory(size_t capacity)
        : buffer_(Allocate(capacity)), capacity_(capacity) {
    }

    RawMemory(const RawMemory&) = delete;
    RawMemory& operator=(const RawMemory& rhs) = delete;

    RawMemory(RawMemory &&other) noexcept
        : buffer_(std::exchange(other.buffer_, nullptr)), capacity_(std::exchange(other.capacity_, 0)) {}

    RawMemory& operator=(RawMemory&& rhs) noexcept {
        if (this != &rhs) {
            Swap(rhs);
        }
        return *this;
    }

    ~RawMemory() {
        Deallocate(buffer_);
    }

    T *operator+(size_t offset) noexcept {
        // Разрешается получать адрес ячейки памяти, следующей за последним элементом массива
        assert(offset <= capacity_);
        return buffer_ + offset;
    }

    const T *operator+(size_t offset) const noexcept {
        return const_cast<RawMemory &>(*this) + offset;
    }

    const T &operator[](size_t index) const noexcept {
        return const_cast<RawMemory &>(*this)[index];
    }

    T &operator[](size_t index) noexcept {
        assert(index < capacity_);
        return buffer_[index];
    }

    void Swap(RawMemory &other) noexcept {
        std::swap(buffer_, other.buffer_);
        std::swap(capacity_, other.capacity_);
    }

    const T *GetAddress() const noexcept {
        return buffer_;
    }

    T *GetAddress() noexcept {
        return buffer_;
    }

    size_t Capacity() const {
        return capacity_;
    }

private:
    // Выделяет сырую память под n элементов и возвращает указатель на неё
    static T *Allocate(size_t n) {
        return n != 0 ? static_cast<T *>(operator new(n * sizeof(T))) : nullptr;
    }

    // Освобождает сырую память, выделенную ранее по адресу buf при помощи Allocate
    static void Deallocate(T *buf) noexcept {
        operator delete(buf);
    }

    T *buffer_ = nullptr;
    size_t capacity_ = 0;
};

template <typename T>
class Vector {
public:
    Vector() = default;

    explicit Vector(size_t size)
        : data_(size), size_(size) {
        std::uninitialized_value_construct_n(data_.GetAddress(), size);
    }

    Vector(const Vector &other)
        : data_(other.size_), size_(other.size_) {
        std::uninitialized_copy_n(other.data_.GetAddress(), other.size_, data_.GetAddress());
    }

    Vector(Vector &&other) noexcept
        : data_(std::move(other.data_)), size_(std::exchange(other.size_, 0)) {}

    ~Vector() {
        std::destroy_n(data_.GetAddress(), size_);
    }

    void Reserve(size_t new_capacity) {
        if (new_capacity <= data_.Capacity()) {
            return;
        }
        RawMemory<T> new_data(new_capacity);
        UnitializedMoveOrCopy_n(data_.GetAddress(), size_, new_data.GetAddress());
        std::destroy_n(data_.GetAddress(), size_);
        data_.Swap(new_data);
    }

    size_t Size() const noexcept {
        return size_;
    }

    size_t Capacity() const noexcept {
        return data_.Capacity();
    }

    const T &operator[](size_t index) const noexcept {
        return const_cast<Vector &>(*this)[index];
    }

    T &operator[](size_t index) noexcept {
        assert(index < size_);
        return data_[index];
    }

    void Swap(Vector &other) noexcept {
        data_.Swap(other.data_);
        std::swap(size_, other.size_);
    }

    Vector& operator=(const Vector& rhs) {
        if (this != &rhs) {
            if (rhs.size_ > data_.Capacity()) {
                Vector rhs_copy(rhs);
                Swap(rhs_copy);
            } else {
                OptimizedRhsCopy(rhs);
            }
        }
        return *this;
    }

    Vector& operator=(Vector&& rhs) noexcept {
        if (this != &rhs) {
            Swap(rhs);
        }
        return *this;
    }

    void Resize(size_t new_size) {
        if (new_size == size_) {
            return;
        } else if (new_size < size_) {
            std::destroy_n(data_.GetAddress() + new_size, size_ - new_size);
        } else {
            Reserve(new_size);
            std::uninitialized_value_construct_n(data_.GetAddress() + size_, new_size - size_);
        }
        size_ = new_size;
    }

    void PushBack(const T& value) {
        EmplaceBack(value);
    }

    void PushBack(T&& value) {
        EmplaceBack(std::move(value));
    }

    void PopBack() noexcept {
        if (size_ != 0) {
            std::destroy_at(data_.GetAddress() + size_ - 1);
            --size_;
        }
    }

    template <typename... Args>
    T& EmplaceBack(Args&&... args) {
        return *(Emplace(cend(), std::forward<Args>(args)...));
    }

    using iterator = T *;
    using const_iterator = const T *;

    iterator begin() noexcept {
        return data_.GetAddress();
    }
    iterator end() noexcept {
        return data_.GetAddress() + size_;
    }
    const_iterator begin() const noexcept {
        return data_.GetAddress();
    }
    const_iterator end() const noexcept {
        return data_.GetAddress() + size_;
    }
    const_iterator cbegin() const noexcept {
        return data_.GetAddress();
    }
    const_iterator cend() const noexcept {
        return data_.GetAddress() + size_;
    }

    template <typename... Args>
    iterator Emplace(const_iterator it_pos, Args&&... args) {
        assert((it_pos >= begin()) && (it_pos <= end()));
        size_t index = static_cast<size_t>(it_pos - data_.GetAddress());
        if (size_ == data_.Capacity()) {
            /* 1) выделить новый блок сырой памяти с удвоенной вместимостью
             * 2) сконструировать в ней вставляемый элемент
             * 3) копируются либо перемещаются элементы, которые предшествуют вставленному элементу
             * 4) копируются либо перемещаются элементы, которые следуют за вставляемым
             * 5) разрушаются исходные элементы, а занимаемая память возвращается обратно в кучу*/
            RawMemory<T> new_data(size_ == 0 ? 1 : size_ * 2);
            std::construct_at(new_data.GetAddress() + index, std::forward<Args>(args)...);

            try {
                UnitializedMoveOrCopy_n(begin(), index, new_data.GetAddress());
            } catch (...) {
                std::destroy_at(new_data.GetAddress() + index);
                throw;
            }
            try {
                UnitializedMoveOrCopy_n(begin() + index, size_ - index, new_data.GetAddress() + index + 1);
            } catch (...) {
                std::destroy_n(new_data.GetAddress(), index + 1);
                throw;
            }
            std::destroy_n(data_.GetAddress(), size_);
            data_.Swap(new_data);
        } else {
            /* 1) создать временный объект
             * 2) в неинициализированной области, следующей за последним элементом, создать копию или переместить значение
             * последнего элемента вектора
             * 3) переместить элементы диапазона [it_pos, end()-1) вправо на один элемент
             * 4) разместить значение во вставляемую позицию*/
            if (it_pos != cend()) {
                T temp_obj(std::forward<Args>(args)...);
                std::construct_at(end(), std::forward<T>(*(end() - 1)));
                std::move_backward(begin() + index, end() - 1, end());
                data_[index] = std::move(temp_obj);
            } else {
                std::construct_at(it_pos, std::forward<Args>(args)...);
            }
        }
        ++size_;
        return data_.GetAddress() + index;
    }

    /* Сначала на место удаляемого элемента нужно переместить следующие за ним элементы.
     * После перемещения элементов в конце вектора останется «пустой» элемент, значение которого содержится в предыдущем элементе
     *  После разрушения объекта в конце вектора и обновления поля size_ удаление элемента можно считать завершённым
     */
    iterator Erase(const_iterator it_pos) /*noexcept(std::is_nothrow_move_assignable_v<T>)*/ {
        assert((it_pos >= begin()) && (it_pos < end()));
        size_t index = static_cast<size_t>(it_pos - data_.GetAddress());
        if constexpr (std::is_nothrow_move_constructible_v<T> || !std::is_copy_constructible_v<T>) {
            std::move(begin() + index + 1, end(), begin() + index);
        } else {
            std::copy(begin() + index + 1, end(), begin() + index);
        }
        PopBack();
        return data_.GetAddress() + index;
    }
    iterator Insert(const_iterator it_pos, const T &value) {
        return Emplace(it_pos, value);
    }
    iterator Insert(const_iterator it_pos, T &&value) {
        return Emplace(it_pos, std::move(value));
    }

private:
    /* Перемещаем элементы в to_addr из from_addr
     * Перемещаем элементы, только если соблюдается хотя бы одно из условий:
     * - конструктор перемещения типа T не выбрасывает исключений;
     * - тип T не имеет копирующего конструктора.
     * В противном случае элементы копируем.*/
    void UnitializedMoveOrCopy_n(T* from_addr, size_t count, T* to_addr) {
        if constexpr (std::is_nothrow_move_constructible_v<T> || !std::is_copy_constructible_v<T>) {
            std::uninitialized_move_n(from_addr, count, to_addr);
        } else {
            std::uninitialized_copy_n(from_addr, count, to_addr);
        }
    }

    /* Выполнить одно из, в зависимости о того, размер чего меньше:
     * - скопировать имеющиеся элементы из источника в приёмник, а избыточные элементы вектора-приёмника разрушить
     * - присвоить существующим элементам приёмника значения соответствующих элементов источника, а оставшиеся скопировать в свободную область
     */
    void OptimizedRhsCopy(const Vector& rhs) {
        std::copy(rhs.begin(), rhs.begin() + std::min(size_, rhs.size_), begin());
        if (rhs.size_ < size_) {
            std::destroy_n(data_.GetAddress() + rhs.size_, size_ - rhs.size_);
        } else {
            std::uninitialized_copy_n(rhs.data_.GetAddress() + size_, rhs.size_ - size_, data_.GetAddress() + size_);
        }
        size_ = rhs.size_;
    }

    RawMemory<T> data_;
    size_t size_ = 0;
};